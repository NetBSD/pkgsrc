$NetBSD: patch-lqr_lqr__energy.c,v 1.1 2012/06/01 21:59:27 wiz Exp $

Needed by gimp-liquid-rescale with clang, otherwise:
graphics/gimp-liquid-rescale/work/.buildlink/lib/liblqr-1.so: undefined reference to `lqr_pixel_get_rgbcol'

--- lqr/lqr_energy.c.orig	2009-05-11 00:08:03.000000000 +0000
+++ lqr/lqr_energy.c
@@ -90,7 +90,7 @@ lqr_pixel_set_norm(gdouble val, void *rg
     }
 }
 
-inline gdouble
+gdouble
 lqr_pixel_get_rgbcol(void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type, gint channel)
 {
     gdouble black_fact = 0;
