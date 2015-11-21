$NetBSD: patch-libvo_vo__gif89a.c,v 1.3 2015/11/21 09:47:23 leot Exp $

* Fix build with giflib 5.1.

--- libvo/vo_gif89a.c.orig	2014-10-05 02:39:08.000000000 +0000
+++ libvo/vo_gif89a.c
@@ -44,6 +44,7 @@
  * entire argument being interpretted as the filename.
  */
 
+#include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -227,7 +228,7 @@ static int config(uint32_t s_width, uint
 		return 1;
 	}
 
-	reduce_cmap = MakeMapObject(256, NULL);
+	reduce_cmap = GifMakeMapObject(256, NULL);
 	if (reduce_cmap == NULL) {
 		free(slice_data); slice_data = NULL;
 		free(reduce_data); reduce_data = NULL;
@@ -284,7 +285,7 @@ static int gif_reduce(int width, int hei
 	}
 
 	R = Ra; G = Ga; B = Ba;
-	return QuantizeBuffer(width, height, &size, R, G, B, dst, colors);
+	return GifQuantizeBuffer(width, height, &size, R, G, B, dst, colors);
 }
 
 static void flip_page(void)
@@ -377,7 +378,7 @@ static void uninit(void)
 	free(gif_filename);
 	free(slice_data);
 	free(reduce_data);
-	if (reduce_cmap != NULL) FreeMapObject(reduce_cmap);
+	if (reduce_cmap != NULL) GifFreeMapObject(reduce_cmap);
 
 	// set the pointers back to null.
 	new_gif = NULL;
