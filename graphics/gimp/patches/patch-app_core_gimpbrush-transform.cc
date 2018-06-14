$NetBSD: patch-app_core_gimpbrush-transform.cc,v 1.1 2018/06/14 17:41:58 jperkin Exp $

Avoid ambiguous function call.

--- app/core/gimpbrush-transform.cc.orig	2018-04-26 13:26:41.000000000 +0000
+++ app/core/gimpbrush-transform.cc
@@ -147,7 +147,7 @@ gimp_brush_real_transform_mask (GimpBrus
    * rectangle.
    */
   const gint fraction_bits = 12;
-  const gint int_multiple  = pow (2, fraction_bits);
+  const gint int_multiple  = pow ((double)2, fraction_bits);
 
   /* In inner loop's bilinear calculation, two numbers that were each
    * previously multiplied by int_multiple are multiplied together.
@@ -169,7 +169,7 @@ gimp_brush_real_transform_mask (GimpBrus
    * 2^9     = 0010 0000 0000
    * 2^9 - 1 = 0001 1111 1111
    */
-  const guint fraction_bitmask = pow(2, fraction_bits) - 1 ;
+  const guint fraction_bitmask = pow((double)2, fraction_bits) - 1 ;
 
   source = gimp_brush_get_mask (brush);
 
@@ -447,7 +447,7 @@ gimp_brush_real_transform_pixmap (GimpBr
    * rectangle.
    */
   const gint fraction_bits = 12;
-  const gint int_multiple  = pow (2, fraction_bits);
+  const gint int_multiple  = pow ((double)2, fraction_bits);
 
   /* In inner loop's bilinear calculation, two numbers that were each
    * previously multiplied by int_multiple are multiplied together.
@@ -469,7 +469,7 @@ gimp_brush_real_transform_pixmap (GimpBr
    * 2^9     = 0010 0000 0000
    * 2^9 - 1 = 0001 1111 1111
    */
-  const guint fraction_bitmask = pow(2, fraction_bits) - 1 ;
+  const guint fraction_bitmask = pow((double)2, fraction_bits) - 1 ;
 
   source = gimp_brush_get_pixmap (brush);
 
