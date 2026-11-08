$NetBSD: patch-source_blender_blenlib_intern_math__base.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- source/blender/blenlib/intern/math_base.cc.orig	2026-09-13 05:53:36.951664001 +0000
+++ source/blender/blenlib/intern/math_base.cc
@@ -37,7 +37,7 @@ double double_round(double x, int ndigits)
     pow2 = 1.0;
     y = (x * pow1) * pow2;
     /* if y overflows, then rounded value is exactly x */
-    if (!isfinite(y)) {
+    if (!std::isfinite(y)) {
       return x;
     }
   }
