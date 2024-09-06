$NetBSD: patch-source_blender_editors_mesh_meshtools.cc,v 1.2 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/mesh/meshtools.cc.orig	2024-08-16 13:50:55.000000000 +0000
+++ source/blender/editors/mesh/meshtools.cc
@@ -912,7 +912,7 @@ static BMVert *editbmesh_get_x_mirror_ve
   int i;
 
   /* ignore nan verts */
-  if ((isfinite(co[0]) == false) || (isfinite(co[1]) == false) || (isfinite(co[2]) == false)) {
+  if ((std::isfinite(co[0]) == false) || (std::isfinite(co[1]) == false) || (std::isfinite(co[2]) == false)) {
     return nullptr;
   }
 
@@ -997,7 +997,7 @@ static float *editmesh_get_mirror_uv(
   float cent[2];
 
   /* ignore nan verts */
-  if (isnan(uv[0]) || !isfinite(uv[0]) || isnan(uv[1]) || !isfinite(uv[1])) {
+  if (std::isnan(uv[0]) || !std::isfinite(uv[0]) || std::isnan(uv[1]) || !std::isfinite(uv[1])) {
     return nullptr;
   }
 
