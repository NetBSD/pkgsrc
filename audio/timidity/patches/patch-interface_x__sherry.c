$NetBSD: patch-interface_x__sherry.c,v 1.1 2011/01/31 23:52:19 wiz Exp $

Fix build with png-1.5. PLTE part in original code is a bit unclear
in purpose.

--- interface/x_sherry.c.orig	2002-07-14 21:19:32.000000000 +0000
+++ interface/x_sherry.c
@@ -782,7 +782,7 @@ static void sry_pal_v2r(uint8 *data)
 static void png_read_func(png_structp png_ptr, char *buff, size_t n)
 {
     struct timidity_file *tf;
-    tf = (struct timidity_file *)png_ptr->io_ptr;
+    tf = (struct timidity_file *)png_get_io_ptr(png_ptr);
     tf_read(buff, 1, n, tf);
 }
 
@@ -815,6 +815,7 @@ static void sry_load_png(uint8 *data)
     int transParent;
     int numTrans;
     png_color_16p transValues;
+    png_color stdColorCube[6*7*6];
 
     numPalette = -1;
     memset(&palette, 0, sizeof(palette));
@@ -909,7 +910,7 @@ static void sry_load_png(uint8 *data)
 	{
 	    if(png_get_valid(pngPtr, infoPtr, PNG_INFO_hIST))
 		png_get_hIST(pngPtr, infoPtr, &hist);
-	    png_set_dither(pngPtr, palette,
+	    png_set_quantize(pngPtr, palette,
 			   numPalette, MAX_SCREEN_COLORS, hist, 1);
 	}
     }
@@ -918,7 +919,6 @@ static void sry_load_png(uint8 *data)
 	/* XXX */
 	/* NOTE 6*7*6 = 252 */
 	/* 6*7*6 = 5*7*6 + 6*6 + 6 */
-	png_color stdColorCube[6*7*6];
 	png_byte r, g, b;
 
 	for(r = 0; r < 6; r++)
@@ -934,13 +934,13 @@ static void sry_load_png(uint8 *data)
 		}
 	    }
 	}
-	png_set_dither(pngPtr, stdColorCube,
+	png_set_quantize(pngPtr, stdColorCube,
 		       6*7*6, MAX_SCREEN_COLORS,
 		       NULL, 1);
 	/*???*/
-	png_set_PLTE(pngPtr, infoPtr, pngPtr->palette, pngPtr->num_palette);
-	palette = pngPtr->palette;
-	numPalette = pngPtr->num_palette;
+	png_set_PLTE(pngPtr, infoPtr, stdColorCube, 6*7*6);
+	palette = stdColorCube;
+	numPalette = 6*7*6;
     }
 
     if(png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS))
