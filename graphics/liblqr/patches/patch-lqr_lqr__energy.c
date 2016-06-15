$NetBSD: patch-lqr_lqr__energy.c,v 1.2 2016/06/15 18:53:33 rumko Exp $

Needed by gimp-liquid-rescale and digikam with clang, otherwise:
graphics/gimp-liquid-rescale/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_rgbcol'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_grey'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_norm'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_std'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_grey'

See https://github.com/carlobaldassi/liblqr/commit/bab7911bce2ea50e1a4db739518fbf7aabfd6888

--- lqr/lqr_energy.c.orig	2009-05-11 00:08:03.000000000 +0000
+++ lqr/lqr_energy.c
@@ -44,7 +44,7 @@
 
 /* read normalised pixel value from
  * rgb buffer at the given index */
-inline gdouble
+gdouble
 lqr_pixel_get_norm(void *rgb, gint rgb_ind, LqrColDepth col_depth)
 {
     switch (col_depth) {
@@ -66,7 +66,7 @@ lqr_pixel_get_norm(void *rgb, gint rgb_i
 
 /* write pixel from normalised value
  * in rgb buffer at the given index */
-inline void
+void
 lqr_pixel_set_norm(gdouble val, void *rgb, gint rgb_ind, LqrColDepth col_depth)
 {
     switch (col_depth) {
@@ -90,7 +90,7 @@ lqr_pixel_set_norm(gdouble val, void *rg
     }
 }
 
-inline gdouble
+gdouble
 lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type, gint channel)
 {
     gdouble black_fact = 0;
@@ -115,7 +115,7 @@ lqr_pixel_get_rgbcol(void *rgb, gint rgb
     }
 }
 
-inline gdouble
+gdouble
 lqr_carver_read_brightness_grey(LqrCarver *r, gint x, gint y)
 {
     gint now = r->raw[y][x];
@@ -123,7 +123,7 @@ lqr_carver_read_brightness_grey(LqrCarve
     return lqr_pixel_get_norm(r->rgb, rgb_ind, r->col_depth);
 }
 
-inline gdouble
+gdouble
 lqr_carver_read_brightness_std(LqrCarver *r, gint x, gint y)
 {
     gdouble red, green, blue;
@@ -205,7 +205,7 @@ lqr_carver_read_brightness(LqrCarver *r,
     return bright * alpha_fact;
 }
 
-inline gdouble
+gdouble
 lqr_carver_read_luma_std(LqrCarver *r, gint x, gint y)
 {
     gdouble red, green, blue;
