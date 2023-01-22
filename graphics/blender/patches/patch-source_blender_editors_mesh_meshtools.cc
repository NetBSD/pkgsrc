$NetBSD: patch-source_blender_editors_mesh_meshtools.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/editors/mesh/meshtools.cc.orig	2022-11-04 00:33:07.000000000 +0000
+++ source/blender/editors/mesh/meshtools.cc
@@ -935,7 +935,7 @@ static BMVert *editbmesh_get_x_mirror_ve
   int i;
 
   /* ignore nan verts */
-  if ((isfinite(co[0]) == false) || (isfinite(co[1]) == false) || (isfinite(co[2]) == false)) {
+  if ((std::isfinite(co[0]) == false) || (std::isfinite(co[1]) == false) || (std::isfinite(co[2]) == false)) {
     return nullptr;
   }
 
