$NetBSD: patch-source_blender_python_mathutils_mathutils__Quaternion.cc,v 1.1 2026/11/08 16:15:20 ryoon Exp $

--- source/blender/python/mathutils/mathutils_Quaternion.cc.orig	2026-09-13 21:33:57.414728414 +0000
+++ source/blender/python/mathutils/mathutils_Quaternion.cc
@@ -57,7 +57,7 @@ static void quat__axis_angle_sanitize(float axis[3], f
 static void quat__axis_angle_sanitize(float axis[3], float *angle)
 {
   if (axis) {
-    if (is_zero_v3(axis) || !isfinite(axis[0]) || !isfinite(axis[1]) || !isfinite(axis[2])) {
+    if (is_zero_v3(axis) || !std::isfinite(axis[0]) || !std::isfinite(axis[1]) || !std::isfinite(axis[2])) {
       axis[0] = 1.0f;
       axis[1] = 0.0f;
       axis[2] = 0.0f;
@@ -70,7 +70,7 @@ static void quat__axis_angle_sanitize(float axis[3], f
   }
 
   if (angle) {
-    if (!isfinite(*angle)) {
+    if (!std::isfinite(*angle)) {
       *angle = 0.0f;
     }
   }
