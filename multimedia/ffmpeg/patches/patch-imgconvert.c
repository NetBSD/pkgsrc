--- libavcodec/imgconvert.c.orig	2008-09-14 21:59:57.000000000 +0100
+++ libavcodec/imgconvert.c	2008-09-14 22:00:56.000000000 +0100
@@ -2108,7 +2108,6 @@
 }
 #endif
 
-#ifndef CONFIG_SWSCALE
 static uint8_t y_ccir_to_jpeg[256];
 static uint8_t y_jpeg_to_ccir[256];
 static uint8_t c_ccir_to_jpeg[256];
@@ -2628,7 +2627,6 @@
     avpicture_free(tmp);
     return ret;
 }
-#endif
 
 /* NOTE: we scan all the pixels to have an exact information */
 static int get_alpha_info_pal8(const AVPicture *src, int width, int height)
