$NetBSD: patch-filter_filter__logo.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- filter/filter_logo.c.orig	2016-05-15 12:53:50.000000000 +0000
+++ filter/filter_logo.c
@@ -36,7 +36,7 @@
 
 /* Note: because of ImageMagick bogosity, this must be included first, so
  * we can undefine the PACKAGE_* symbols it splats into our namespace */
-#include <magick/api.h>
+#include <MagickCore/MagickCore.h>
 #undef PACKAGE_BUGREPORT
 #undef PACKAGE_NAME
 #undef PACKAGE_STRING
@@ -573,7 +573,7 @@ int tc_filter(frame_list_t *ptr_, char *
         /* Set up image/video coefficient lookup tables */
         if (img_coeff_lookup[0] < 0) {
             int i;
-            float maxrgbval = (float)MaxRGB; // from ImageMagick
+            float maxrgbval = 255.0f;
 
             for (i = 0; i <= MAX_UINT8_VAL; i++) {
                 float x = (float)ScaleCharToQuantum(i);
@@ -702,16 +702,16 @@ int tc_filter(frame_list_t *ptr_, char *
                 video_buf = ptr->video_buf + 3 * ((row + mfd->posy) * vob->ex_v_width + mfd->posx);
 
                 for (col = 0; col < mfd->image->columns; col++) {
-                    opacity = pixel_packet->opacity;
+                    opacity = pixel_packet->alpha;
 
                     if (do_fade)
-                        opacity += (Quantum)((MaxRGB - opacity) * fade_coeff);
+                        opacity += (Quantum)((255 - opacity) * fade_coeff);
 
                     if (opacity == 0) {
                         *(video_buf + r_off) = ScaleQuantumToChar(pixel_packet->red);
                         *(video_buf + g_off) = ScaleQuantumToChar(pixel_packet->green);
                         *(video_buf + b_off) = ScaleQuantumToChar(pixel_packet->blue);
-                    } else if (opacity < MaxRGB) {
+                    } else if (opacity < 255) {
                         unsigned char opacity_uchar = ScaleQuantumToChar(opacity);
                         img_coeff = img_coeff_lookup[opacity_uchar];
                         vid_coeff = vid_coeff_lookup[opacity_uchar];
@@ -745,10 +745,10 @@ int tc_filter(frame_list_t *ptr_, char *
                 vid_pixel_V = vid_pixel_U + vid_size/4;
                 for (col = 0; col < mfd->images->columns; col++) {
                     int do_UV_pixels = (mfd->grayout == 0 && !(row % 2) && !(col % 2)) ? 1 : 0;
-                    opacity = pixel_packet->opacity;
+                    opacity = pixel_packet->alpha;
 
                     if (do_fade)
-                        opacity += (Quantum)((MaxRGB - opacity) * fade_coeff);
+                        opacity += (Quantum)((255 - opacity) * fade_coeff);
 
                     if (opacity == 0) {
                         *vid_pixel_Y = *img_pixel_Y;
@@ -756,7 +756,7 @@ int tc_filter(frame_list_t *ptr_, char *
                                 *vid_pixel_U = *img_pixel_U;
                                 *vid_pixel_V = *img_pixel_V;
                         }
-                    } else if (opacity < MaxRGB) {
+                    } else if (opacity < 255) {
                         unsigned char opacity_uchar = ScaleQuantumToChar(opacity);
                         img_coeff = img_coeff_lookup[opacity_uchar];
                         vid_coeff = vid_coeff_lookup[opacity_uchar];
