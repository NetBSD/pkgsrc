$NetBSD: patch-Quake_main_sdl.c,v 1.1 2023/03/02 03:13:53 charlotte Exp $

Remove faulty SDL2 version check.

Original commit from upstream:

commit 2a67d5bcb236212b0cd8ed7abae9e7089af34ff2
Author: Ozkan Sezer <sezeroz@gmail.com>
Date:   Tue May 24 20:55:04 2022 +0300

    removed SDL version checks at runtime for compatibility with new SDL2:
    
    With the new SDL2 versioning scheme, SDL_VERSIONNUM macro overflows the
    minor version into the thousands digit after 2.9.0, e.g. encodes 2.23.0
    as 4300, and we used to reject that thinking it is SDL v3 or something.

--- Quake/main_sdl.c.orig	2023-02-27 23:22:39.979960547 -0800
+++ Quake/main_sdl.c	2023-02-27 23:27:28.947967635 -0800
@@ -22,20 +22,9 @@
 */
 
 #include "quakedef.h"
-#if defined(SDL_FRAMEWORK) || defined(NO_SDL_CONFIG)
 #include <SDL2/SDL.h>
-#else
-#include "SDL.h"
-#endif
 #include <stdio.h>
 
-/* need at least SDL_2.0.0 */
-#define SDL_MIN_X	2
-#define SDL_MIN_Y	0
-#define SDL_MIN_Z	0
-#define SDL_REQUIREDVERSION	(SDL_VERSIONNUM(SDL_MIN_X,SDL_MIN_Y,SDL_MIN_Z))
-#define SDL_NEW_VERSION_REJECT	(SDL_VERSIONNUM(3,0,0))
-
 static void Sys_AtExit (void)
 {
 	SDL_Quit();
@@ -48,15 +37,6 @@
 	SDL_GetVersion(&v);
 
 	Sys_Printf("Found SDL version %i.%i.%i\n",sdl_version->major,sdl_version->minor,sdl_version->patch);
-	if (SDL_VERSIONNUM(sdl_version->major,sdl_version->minor,sdl_version->patch) < SDL_REQUIREDVERSION)
-	{	/*reject running under older SDL versions */
-		Sys_Error("You need at least v%d.%d.%d of SDL to run this game.", SDL_MIN_X,SDL_MIN_Y,SDL_MIN_Z);
-	}
-	if (SDL_VERSIONNUM(sdl_version->major,sdl_version->minor,sdl_version->patch) >= SDL_NEW_VERSION_REJECT)
-	{	/*reject running under newer (1.3.x) SDL */
-		Sys_Error("Your version of SDL library is incompatible with me.\n"
-			  "You need a library version in the line of %d.%d.%d\n", SDL_MIN_X,SDL_MIN_Y,SDL_MIN_Z);
-	}
 
 	if (SDL_Init(0) < 0)
 	{
