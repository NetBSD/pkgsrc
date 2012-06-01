$NetBSD: patch-lqr_lqr__energy__priv.h,v 1.1 2012/06/01 21:59:27 wiz Exp $

Needed by gimp-liquid-rescale with clang, otherwise:
graphics/gimp-liquid-rescale/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_rgbcol'

--- lqr/lqr_energy_priv.h.orig	2009-05-11 00:08:03.000000000 +0000
+++ lqr/lqr_energy_priv.h
@@ -40,7 +40,7 @@
 
 inline gdouble lqr_pixel_get_norm(void *src, gint src_ind, LqrColDepth col_depth);
 inline void lqr_pixel_set_norm(gdouble val, void *rgb, gint rgb_ind, LqrColDepth col_depth);
-inline gdouble lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type,
+gdouble lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type,
                                     gint channel);
 inline gdouble lqr_carver_read_brightness_grey(LqrCarver *r, gint x, gint y);
 inline gdouble lqr_carver_read_brightness_std(LqrCarver *r, gint x, gint y);
