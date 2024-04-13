#ifndef ENTITE_H
#define ENTITE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "projectile.h"
#include "fonctions.h"
#include "carte.h"

#define DIM_SPRITE_ENNEMI_X 128
#define DIM_SPRITE_ENNEMI_Y 184

#define CHAMP_DETECTION 500
#define MAX_PROJ_ENNEMI 2

#define NB_ENNEMI 50

typedef struct ennemi_s ennemi_t;
typedef struct joueur_s joueur_t;

typedef struct point_s{
    int x;
    int y;
} point_t;

struct joueur_s {
    int id;
    int x;
    int y;
    int pv;
    int pvMax;
    int attaque;
    int vitesse;
};

struct ennemi_s {
    int id;
    float x;
    float y;
    
    float vx;
    float vy;

    int pv;
    int pvMax;
    int attaque;
    float vitesse;
    int detection;

    int gauche;
    int droite;

    int mort;

    Uint32 delta; /* Variable servant à calculer la durée d'apparition d'un ennemi */

    SDL_Rect rect;
    SDL_Rect sprite;

    void (*initEnnemi)(ennemi_t *ennemi, float x, float y, int id, int pvMax, int attaque);
    void (*updateEnnemi)(ennemi_t * ennemi, SDL_Rect * cameraRect, SDL_Rect * playerRect, int tabColision[NB_TILE_WIDTH][NB_TILE_HEIGHT], projectiles_t projEnnemi[MAX_PROJ], int *projNbEnnemi, int temp_vivant);
    void (*renderEnnemi)(SDL_Renderer * rendu, ennemi_t * ennemi, int frame);
    void (*renderVecteur)(SDL_Renderer * rendu, ennemi_t * ennemi, SDL_Rect * playerRect);
};

void initTabEnnemi(ennemi_t tabEnnemi[NB_ENNEMI]);
void initialiserJoueur(joueur_t * joueur);
void ennemi_creer(ennemi_t * ennemi);
void initEnnemi(ennemi_t * ennemi, float x, float y, int id, int pvMax, int attaque);
void initEnnemisVague(ennemi_t tabEnnemi[NB_ENNEMI], int nb_ennemis);
void updateEnnemi(ennemi_t * ennemi, SDL_Rect * cameraRect, SDL_Rect * playerRect, int tabColision[NB_TILE_WIDTH][NB_TILE_HEIGHT], projectiles_t projEnnemi[MAX_PROJ], int *projNbEnnemi, int temp_vivant);
void renderEnnemi(SDL_Renderer *rendu, ennemi_t *ennemi, int frame);
void renderVecteur(SDL_Renderer *rendu, ennemi_t *ennemi, SDL_Rect * playerRect);
void DessinerPixel(int x, int y, SDL_Renderer *rendu);
void DessinerLigneEnnemiJoueur(point_t A, point_t B, SDL_Renderer *rendu);
void DessinerLigneEnnemiVu(point_t A, point_t B, SDL_Renderer *rendu);
void chargerTexturesEnnemi(SDL_Renderer *rendu);

void initEnnemis(
    projectiles_t projJoueur[MAX_PROJ],
    projectiles_t projEnnemi[MAX_PROJ],
    joueur_t *joueur,
    ennemi_t ennemi[NB_ENNEMI],
    SDL_Renderer *rendu
);

#endif // ENTITE_H
