$NetBSD: patch-gui_stk.c,v 1.1 2011/02/01 00:29:26 wiz Exp $

Fix build with png-1.5.

--- gui/stk.c.orig	2010-10-04 13:40:45.000000000 +0000
+++ gui/stk.c
@@ -105,7 +105,7 @@ static SDL_Surface *IMG_LoadPNG_RW(SDL_R
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		IMG_SetError("Error reading the PNG file.");
 		goto done;
 	}
@@ -174,9 +174,9 @@ static SDL_Surface *IMG_LoadPNG_RW(SDL_R
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
@@ -184,7 +184,7 @@ static SDL_Surface *IMG_LoadPNG_RW(SDL_R
 		}
 	}
 	surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
-			bit_depth*info_ptr->channels, Rmask,Gmask,Bmask,Amask);
+			bit_depth*png_get_channels(png_ptr, info_ptr), Rmask,Gmask,Bmask,Amask);
 	if ( surface == NULL ) {
 		IMG_SetError("Out of memory");
 		goto done;
@@ -229,12 +229,18 @@ static SDL_Surface *IMG_LoadPNG_RW(SDL_R
 		    palette->colors[i].g = i;
 		    palette->colors[i].b = i;
 		}
-	    } else if (info_ptr->num_palette > 0 ) {
-		palette->ncolors = info_ptr->num_palette; 
-		for( i=0; i<info_ptr->num_palette; ++i ) {
-		    palette->colors[i].b = info_ptr->palette[i].blue;
-		    palette->colors[i].g = info_ptr->palette[i].green;
-		    palette->colors[i].r = info_ptr->palette[i].red;
+	    } else {
+		png_colorp file_palette;
+		int file_num_palette;
+		png_get_PLTE(png_ptr, info_ptr, &file_palette,
+			     &file_num_palette);
+		if (file_num_palette > 0 ) {
+		    palette->ncolors = file_num_palette;
+		    for( i=0; i<file_num_palette; ++i ) {
+		        palette->colors[i].b = file_palette[i].blue;
+		        palette->colors[i].g = file_palette[i].green;
+		        palette->colors[i].r = file_palette[i].red;
+		    }
 		}
 	    }
 	}
