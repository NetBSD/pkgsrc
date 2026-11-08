$NetBSD: patch-source_blender_geometry_intern_mesh__boolean.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/geometry/intern/mesh_boolean.cc.orig	2026-09-13 20:42:33.920595181 +0000
+++ source/blender/geometry/intern/mesh_boolean.cc
@@ -348,13 +348,13 @@ static float3 clean_float3(const float3 &co)
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
