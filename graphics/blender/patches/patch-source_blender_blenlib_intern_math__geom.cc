$NetBSD: patch-source_blender_blenlib_intern_math__geom.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

isfinite() is in std, BLI_math_base.hh does include <cmath>.

--- ./source/blender/blenlib/intern/math_geom.cc.orig	2024-06-08 23:38:06.000000000 +0000
+++ ./source/blender/blenlib/intern/math_geom.cc
@@ -1876,7 +1876,7 @@ bool isect_ray_tri_watertight_v3(const f
 
   /* Calculate determinant. */
   det = u + v + w;
-  if (UNLIKELY(det == 0.0f || !isfinite(det))) {
+  if (UNLIKELY(det == 0.0f || !std::isfinite(det))) {
     return false;
   }
 
@@ -4058,7 +4058,7 @@ static float mean_value_half_tan_v3(cons
     const float dot = dot_v3v3(d_curr->dir, d_next->dir);
     const float len = d_curr->len * d_next->len;
     const float result = (len - dot) / area;
-    if (isfinite(result)) {
+    if (std::isfinite(result)) {
       return result;
     }
   }
@@ -4083,7 +4083,7 @@ static double mean_value_half_tan_v2_db(
     const double dot = dot_v2v2_db(d_curr->dir, d_next->dir);
     const double len = d_curr->len * d_next->len;
     const double result = (len - dot) / area;
-    if (isfinite(result)) {
+    if (std::isfinite(result)) {
       return result;
     }
   }
