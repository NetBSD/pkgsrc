$NetBSD: patch-src_lib_image2_sdl__image_IMG__png.c,v 1.1 2011/04/05 11:56:30 wiz Exp $

Fix build with png-1.5.

--- src/lib/image2/sdl_image/IMG_png.c.orig	2002-08-05 10:43:09.000000000 +0000
+++ src/lib/image2/sdl_image/IMG_png.c
@@ -138,7 +138,7 @@ SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *s
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		IMG_SetError("Error reading the PNG file.");
 		goto done;
 	}
@@ -207,9 +207,9 @@ SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *s
 			Rmask = 0x000000FF;
 			Gmask = 0x0000FF00;
 			Bmask = 0x00FF0000;
-			Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+			Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
 		} else {
-		        int s = (info_ptr->channels == 4) ? 0 : 8;
+		        int s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
 			Rmask = 0xFF000000 >> s;
 			Gmask = 0x00FF0000 >> s;
 			Bmask = 0x0000FF00 >> s;
@@ -217,7 +217,7 @@ SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *s
 		}
 	}
 	surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
-			bit_depth*info_ptr->channels, Rmask,Gmask,Bmask,Amask);
+			bit_depth*png_get_channels(png_ptr, info_ptr), Rmask,Gmask,Bmask,Amask);
 	if ( surface == NULL ) {
 		IMG_SetError("Out of memory");
 		goto done;
@@ -255,6 +255,10 @@ SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *s
 	/* Load the palette, if any */
 	palette = surface->format->palette;
 	if ( palette ) {
+	    png_colorp pngpalette;
+	    int pngnum_palette;
+
+	    png_get_PLTE(png_ptr, info_ptr, &pngpalette, &pngnum_palette);
 	    if(color_type == PNG_COLOR_TYPE_GRAY) {
 		palette->ncolors = 256;
 		for(i = 0; i < 256; i++) {
@@ -262,12 +266,12 @@ SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *s
 		    palette->colors[i].g = i;
 		    palette->colors[i].b = i;
 		}
-	    } else if (info_ptr->num_palette > 0 ) {
-		palette->ncolors = info_ptr->num_palette; 
-		for( i=0; i<info_ptr->num_palette; ++i ) {
-		    palette->colors[i].b = info_ptr->palette[i].blue;
-		    palette->colors[i].g = info_ptr->palette[i].green;
-		    palette->colors[i].r = info_ptr->palette[i].red;
+	    } else if (pngnum_palette > 0 ) {
+		palette->ncolors = pngnum_palette; 
+		for( i=0; i<pngnum_palette; ++i ) {
+		    palette->colors[i].b = pngpalette[i].blue;
+		    palette->colors[i].g = pngpalette[i].green;
+		    palette->colors[i].r = pngpalette[i].red;
 		}
 	    }
 	}
