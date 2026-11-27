$NetBSD: patch-source_blender_blenlib_intern_math__rotation_c.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/blenlib/intern/math_rotation_c.cc.orig	2026-08-26 11:25:46.704018999 +0000
+++ source/blender/blenlib/intern/math_rotation_c.cc
@@ -380,7 +380,7 @@ static void mat3_normalized_to_quat_with_checks(float 
 static void mat3_normalized_to_quat_with_checks(float q[4], float mat[3][3])
 {
   const float det = determinant_m3_array(mat);
-  if (UNLIKELY(!isfinite(det))) {
+  if (UNLIKELY(!std::isfinite(det))) {
     unit_m3(mat);
   }
   else if (UNLIKELY(det < 0.0f)) {
