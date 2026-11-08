$NetBSD: patch-source_blender_bmesh_tools_bmesh__boolean.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/bmesh/tools/bmesh_boolean.cc.orig	2026-09-13 20:18:01.947960187 +0000
+++ source/blender/bmesh/tools/bmesh_boolean.cc
@@ -31,13 +31,13 @@ static float3 clean_float3(const float3 &co)
 static float3 clean_float3(const float3 &co)
 {
   float3 cleaned = co;
-  if (!isfinite(co[0])) [[unlikely]] {
+  if (!std::isfinite(co[0])) [[unlikely]] {
     cleaned[0] = 0.0f;
   }
-  if (!isfinite(co[1])) [[unlikely]] {
+  if (!std::isfinite(co[1])) [[unlikely]] {
     cleaned[1] = 0.0f;
   }
-  if (!isfinite(co[2])) [[unlikely]] {
+  if (!std::isfinite(co[2])) [[unlikely]] {
     cleaned[2] = 0.0f;
   }
   return cleaned;
