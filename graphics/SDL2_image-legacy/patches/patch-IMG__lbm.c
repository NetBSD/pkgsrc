$NetBSD: patch-IMG__lbm.c,v 1.1 2024/05/06 18:05:32 nia Exp $

Fix various security issues,
CVE-2017-14440
CVE-2017-12122

Taken from Ubuntu Linux.

--- IMG_lbm.c.orig	2016-01-03 05:52:28.000000000 +0000
+++ IMG_lbm.c
@@ -187,6 +187,11 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 
         if ( !SDL_memcmp( id, "CMAP", 4 ) ) /* palette ( Color Map ) */
         {
+            if (size > sizeof (colormap)) {
+                error="colormap size is too large";
+                goto done;
+            }
+
             if ( !SDL_RWread( src, &colormap, size, 1 ) )
             {
                 error="error reading CMAP chunk";
@@ -237,6 +242,12 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
         nbplanes = 1;
     }
 
+    if ((nbplanes != 1) && (nbplanes != 4) && (nbplanes != 8) && (nbplanes != 24))
+    {
+        error="unsupported number of color planes";
+        goto done;
+    }
+
     stencil = (bmhd.mask & 1);   /* There is a mask ( 'stencil' ) */
 
     /* Allocate memory for a temporary buffer ( used for
@@ -249,7 +260,7 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
         goto done;
     }
 
-    if ( ( Image = SDL_CreateRGBSurface( SDL_SWSURFACE, width, bmhd.h, (bmhd.planes==24 || flagHAM==1)?24:8, 0, 0, 0, 0 ) ) == NULL )
+    if ( ( Image = SDL_CreateRGBSurface( SDL_SWSURFACE, width, bmhd.h, (nbplanes==24 || flagHAM==1)?24:8, 0, 0, 0, 0 ) ) == NULL )
        goto done;
 
     if ( bmhd.mask & 2 )               /* There is a transparent color */
@@ -276,7 +287,7 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
         /* The 32 last colors are the same but divided by 2 */
         /* Some Amiga pictures save 64 colors with 32 last wrong colors, */
         /* they shouldn't !, and here we overwrite these 32 bad colors. */
-        if ( (nbcolors==32 || flagEHB ) && (1<<bmhd.planes)==64 )
+        if ( (nbcolors==32 || flagEHB ) && (1<<nbplanes)==64 )
         {
             nbcolors = 64;
             ptr = &colormap[0];
@@ -290,8 +301,8 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 
         /* If nbcolors < 2^nbplanes, repeat the colormap */
         /* This happens when pictures have a stencil mask */
-        if ( nbrcolorsfinal > (1<<bmhd.planes) ) {
-            nbrcolorsfinal = (1<<bmhd.planes);
+        if ( nbrcolorsfinal > (1<<nbplanes) ) {
+            nbrcolorsfinal = (1<<nbplanes);
         }
         for ( i=nbcolors; i < (Uint32)nbrcolorsfinal; i++ )
         {
