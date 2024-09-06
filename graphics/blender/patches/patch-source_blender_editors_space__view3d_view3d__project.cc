$NetBSD: patch-source_blender_editors_space__view3d_view3d__project.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/space_view3d/view3d_project.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/space_view3d/view3d_project.cc
@@ -209,7 +209,7 @@ eV3DProjStatus ED_view3d_project_float_e
   float tvec[2];
   eV3DProjStatus ret = ed_view3d_project__internal(region, perspmat, is_local, co, tvec, flag);
   if (ret == V3D_PROJ_RET_OK) {
-    if (isfinite(tvec[0]) && isfinite(tvec[1])) {
+    if (std::isfinite(tvec[0]) && std::isfinite(tvec[1])) {
       copy_v2_v2(r_co, tvec);
     }
     else {
