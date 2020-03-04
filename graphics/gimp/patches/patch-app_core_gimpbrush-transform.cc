$NetBSD: patch-app_core_gimpbrush-transform.cc,v 1.2 2020/03/04 12:46:01 wiz Exp $

Avoid ambiguous function call.

--- app/core/gimpbrush-transform.cc.orig	2020-02-16 14:57:59.000000000 +0000
+++ app/core/gimpbrush-transform.cc
@@ -159,7 +159,7 @@ gimp_brush_real_transform_mask (GimpBrus
    * rectangle.
    */
   const gint fraction_bits = 12;
-  const gint int_multiple  = pow (2, fraction_bits);
+  const gint int_multiple  = pow ((double)2, fraction_bits);
 
   /* In inner loop's bilinear calculation, two numbers that were each
    * previously multiplied by int_multiple are multiplied together.
@@ -181,7 +181,7 @@ gimp_brush_real_transform_mask (GimpBrus
    * 2^9     = 0010 0000 0000
    * 2^9 - 1 = 0001 1111 1111
    */
-  const guint fraction_bitmask = pow(2, fraction_bits) - 1 ;
+  const guint fraction_bitmask = pow((double)2, fraction_bits) - 1 ;
 
   gimp_brush_transform_get_scale (scale, aspect_ratio,
                                   &scale_x, &scale_y);
@@ -473,7 +473,7 @@ gimp_brush_real_transform_pixmap (GimpBr
    * rectangle.
    */
   const gint fraction_bits = 12;
-  const gint int_multiple  = pow (2, fraction_bits);
+  const gint int_multiple  = pow ((double)2, fraction_bits);
 
   /* In inner loop's bilinear calculation, two numbers that were each
    * previously multiplied by int_multiple are multiplied together.
@@ -495,7 +495,7 @@ gimp_brush_real_transform_pixmap (GimpBr
    * 2^9     = 0010 0000 0000
    * 2^9 - 1 = 0001 1111 1111
    */
-  const guint fraction_bitmask = pow(2, fraction_bits) - 1 ;
+  const guint fraction_bitmask = pow((double)2, fraction_bits) - 1 ;
 
   gimp_brush_transform_get_scale (scale, aspect_ratio,
                                   &scale_x, &scale_y);
