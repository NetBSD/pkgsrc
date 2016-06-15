$NetBSD: patch-lqr_lqr__energy__priv.h,v 1.2 2016/06/15 18:53:33 rumko Exp $

Needed by gimp-liquid-rescale and digikam with clang, otherwise:
graphics/gimp-liquid-rescale/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_rgbcol'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_grey'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_norm'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_std'
graphics/digikam/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_carver_read_brightness_grey'

https://github.com/carlobaldassi/liblqr/commit/bab7911bce2ea50e1a4db739518fbf7aabfd6888

--- lqr/lqr_energy_priv.h.orig	2009-05-11 00:08:03.000000000 +0000
+++ lqr/lqr_energy_priv.h
@@ -38,15 +38,15 @@
 #define LQR_SATURATE_(x) (1 / (1 + (1 / (x))))
 #define LQR_SATURATE(x) ((x) >= 0 ? LQR_SATURATE_(x) : -LQR_SATURATE_(-x))
 
-inline gdouble lqr_pixel_get_norm(void *src, gint src_ind, LqrColDepth col_depth);
-inline void lqr_pixel_set_norm(gdouble val, void *rgb, gint rgb_ind, LqrColDepth col_depth);
-inline gdouble lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type,
+gdouble lqr_pixel_get_norm(void *src, gint src_ind, LqrColDepth col_depth);
+void lqr_pixel_set_norm(gdouble val, void *rgb, gint rgb_ind, LqrColDepth col_depth);
+gdouble lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type,
                                     gint channel);
-inline gdouble lqr_carver_read_brightness_grey(LqrCarver *r, gint x, gint y);
-inline gdouble lqr_carver_read_brightness_std(LqrCarver *r, gint x, gint y);
+gdouble lqr_carver_read_brightness_grey(LqrCarver *r, gint x, gint y);
+gdouble lqr_carver_read_brightness_std(LqrCarver *r, gint x, gint y);
 gdouble lqr_carver_read_brightness_custom(LqrCarver *r, gint x, gint y);
 inline gdouble lqr_carver_read_brightness(LqrCarver *r, gint x, gint y);
-inline gdouble lqr_carver_read_luma_std(LqrCarver *r, gint x, gint y);
+gdouble lqr_carver_read_luma_std(LqrCarver *r, gint x, gint y);
 inline gdouble lqr_carver_read_luma(LqrCarver *r, gint x, gint y);
 inline gdouble lqr_carver_read_rgba(LqrCarver *r, gint x, gint y, gint channel);
 inline gdouble lqr_carver_read_custom(LqrCarver *r, gint x, gint y, gint channel);
