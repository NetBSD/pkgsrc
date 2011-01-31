$NetBSD: patch-lib-src_enigma-core_IMG__SavePNG.c,v 1.1 2011/02/01 00:08:48 wiz Exp $

Fix build with png-1.5.

--- lib-src/enigma-core/IMG_SavePNG.c.orig	2005-11-24 23:17:06.000000000 +0000
+++ lib-src/enigma-core/IMG_SavePNG.c
@@ -84,7 +84,7 @@ int IMG_SavePNG_RW(SDL_Surface *face, SD
                 png_bytep *row_pointers = 0;
 
                 /* Set error handling. */
-                if (setjmp(png_ptr->jmpbuf)) {
+                if (setjmp(png_jmpbuf(png_ptr))) {
                     IMG_SetError("Error writing the PNG file");
                 }
                 else {
