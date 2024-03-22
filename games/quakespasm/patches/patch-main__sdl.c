$NetBSD: patch-main__sdl.c,v 1.1 2024/03/22 23:05:42 nia Exp $

Include the proper header for the SDL_main alias.

--- main_sdl.c.orig	2024-03-22 22:32:47.000000000 +0000
+++ main_sdl.c
@@ -31,6 +31,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #else
 #include "SDL.h"
 #endif
+#include <SDL_main.h>
 #include <stdio.h>
 
 static void Sys_AtExit (void)
@@ -60,12 +61,6 @@ static void Sys_InitSDL (void)
 
 static quakeparms_t	parms;
 
-// On OS X we call SDL_main from the launcher, but SDL2 doesn't redefine main
-// as SDL_main on OS X anymore, so we do it ourselves.
-#if defined(USE_SDL2) && defined(__APPLE__)
-#define main SDL_main
-#endif
-
 int main(int argc, char *argv[])
 {
 	int		t;
