$NetBSD: patch-src_video_png.c,v 1.2 2011/08/05 00:56:37 wiz Exp $

Fix build with png-1.5.
https://bugs.launchpad.net/stratagus/+bug/821210

--- src/video/png.c.orig	2004-06-26 22:38:20.000000000 +0000
+++ src/video/png.c
@@ -133,7 +133,7 @@ Graphic* LoadGraphicPNG(const char* name
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		fprintf(stderr, "Error reading the PNG file.");
 		goto done;
 	}
@@ -212,11 +212,11 @@ Graphic* LoadGraphicPNG(const char* name
 			Rmask = 0x000000FF;
 			Gmask = 0x0000FF00;
 			Bmask = 0x00FF0000;
-			Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+			Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
 		} else {
 			int s;
 
-			s = (info_ptr->channels == 4) ? 0 : 8;
+			s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
 			Rmask = 0xFF000000 >> s;
 			Gmask = 0x00FF0000 >> s;
 			Bmask = 0x0000FF00 >> s;
@@ -224,7 +224,7 @@ Graphic* LoadGraphicPNG(const char* name
 		}
 	}
 	surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
-		bit_depth * info_ptr->channels, Rmask, Gmask, Bmask, Amask);
+		bit_depth * png_get_channels(png_ptr, info_ptr), Rmask, Gmask, Bmask, Amask);
 	if (surface == NULL) {
 		fprintf(stderr, "Out of memory");
 		goto done;
@@ -270,12 +270,17 @@ Graphic* LoadGraphicPNG(const char* name
 				palette->colors[i].g = i;
 				palette->colors[i].b = i;
 			}
-		} else if (info_ptr->num_palette > 0) {
-			palette->ncolors = info_ptr->num_palette;
-			for (i = 0; i < info_ptr->num_palette; ++i) {
-				palette->colors[i].b = info_ptr->palette[i].blue;
-				palette->colors[i].g = info_ptr->palette[i].green;
-				palette->colors[i].r = info_ptr->palette[i].red;
+		} else {
+			png_colorp pngpalette;
+			int num_palette;
+			png_get_PLTE(png_ptr, info_ptr, &pngpalette, &num_palette);
+			if (num_palette > 0) {
+				palette->ncolors = num_palette;
+				for (i = 0; i < num_palette; ++i) {
+					palette->colors[i].b = pngpalette[i].blue;
+					palette->colors[i].g = pngpalette[i].green;
+					palette->colors[i].r = pngpalette[i].red;
+				}
 			}
 		}
 	}
@@ -331,7 +336,7 @@ void SaveScreenshotPNG(const char* name)
 		return;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		/* If we get here, we had a problem reading the file */
 		fclose(fp);
 		png_destroy_write_struct(&png_ptr, &info_ptr);
