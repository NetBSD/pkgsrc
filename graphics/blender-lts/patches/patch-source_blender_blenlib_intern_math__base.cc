$NetBSD: patch-source_blender_blenlib_intern_math__base.cc,v 1.1 2026/11/27 13:46:27 adam Exp $

--- source/blender/blenlib/intern/math_base.cc.orig	2026-08-26 12:43:47.463427124 +0000
+++ source/blender/blenlib/intern/math_base.cc
@@ -35,7 +35,7 @@ double double_round(double x, int ndigits)
     pow2 = 1.0;
     y = (x * pow1) * pow2;
     /* if y overflows, then rounded value is exactly x */
-    if (!isfinite(y)) {
+    if (!std::isfinite(y)) {
       return x;
     }
   }
