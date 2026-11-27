$NetBSD: patch-source_blender_geometry_intern_mesh__boolean.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/geometry/intern/mesh_boolean.cc.orig	2026-08-26 12:50:58.596457333 +0000
+++ source/blender/geometry/intern/mesh_boolean.cc
@@ -81,13 +81,13 @@ static float3 clean_float3(const float3 &co)
 static float3 clean_float3(const float3 &co)
 {
   float3 cleaned = co;
-  if (UNLIKELY(!isfinite(co[0]))) {
+  if (UNLIKELY(!std::isfinite(co[0]))) {
     cleaned[0] = 0.0f;
   }
-  if (UNLIKELY(!isfinite(co[1]))) {
+  if (UNLIKELY(!std::isfinite(co[1]))) {
     cleaned[1] = 0.0f;
   }
-  if (UNLIKELY(!isfinite(co[2]))) {
+  if (UNLIKELY(!std::isfinite(co[2]))) {
     cleaned[2] = 0.0f;
   }
   return cleaned;
