$NetBSD: patch-libvo_vo__gif89a.c,v 1.1 2013/07/06 07:07:18 ryoon Exp $

* Fix build with giflib 5.0.

--- libvo/vo_gif89a.c.orig	2011-05-07 10:59:11.000000000 +0000
+++ libvo/vo_gif89a.c
@@ -44,6 +44,7 @@
  * entire argument being interpretted as the filename.
  */
 
+#include <stddef.h>
 #include <gif_lib.h>
 
 #include <stdio.h>
@@ -196,7 +197,7 @@ static int config(uint32_t s_width, uint
 	mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: Some functionality has been disabled.\n");
 #endif
 
-	new_gif = EGifOpenFileName(gif_filename, 0);
+	new_gif = EGifOpenFileName(gif_filename, 0, NULL);
 	if (new_gif == NULL) {
 		mp_msg(MSGT_VO, MSGL_ERR, "GIF89a: error opening file \"%s\" for output.\n", gif_filename);
 		return 1;
@@ -215,7 +216,7 @@ static int config(uint32_t s_width, uint
 		return 1;
 	}
 
-	reduce_cmap = MakeMapObject(256, NULL);
+	reduce_cmap = GifMakeMapObject(256, NULL);
 	if (reduce_cmap == NULL) {
 		free(slice_data); slice_data = NULL;
 		free(reduce_data); reduce_data = NULL;
@@ -267,7 +268,7 @@ static int gif_reduce(int width, int hei
 	}
 
 	R = Ra; G = Ga; B = Ba;
-	return QuantizeBuffer(width, height, &size, R, G, B, dst, colors);
+	return GifQuantizeBuffer(width, height, &size, R, G, B, dst, colors);
 }
 
 static void flip_page(void)
@@ -365,7 +366,7 @@ static void uninit(void)
 	free(gif_filename);
 	free(slice_data);
 	free(reduce_data);
-	if (reduce_cmap != NULL) FreeMapObject(reduce_cmap);
+	if (reduce_cmap != NULL) GifFreeMapObject(reduce_cmap);
 
 	// set the pointers back to null.
 	new_gif = NULL;
