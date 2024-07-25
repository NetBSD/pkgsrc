$NetBSD: patch-source_blender_modifiers_intern_MOD__surfacedeform.cc,v 1.1 2024/07/25 06:00:39 ryoon Exp $

--- source/blender/modifiers/intern/MOD_surfacedeform.cc.orig	2024-07-02 09:55:16.595931240 +0000
+++ source/blender/modifiers/intern/MOD_surfacedeform.cc
@@ -788,7 +788,7 @@ BLI_INLINE SDefBindWeightData *computeBi
       corner_angle_weights[0] = bpoly->point_edgemid_angles[0] / bpoly->corner_edgemid_angles[0];
       corner_angle_weights[1] = bpoly->point_edgemid_angles[1] / bpoly->corner_edgemid_angles[1];
 
-      if (isnan(corner_angle_weights[0]) || isnan(corner_angle_weights[1])) {
+      if (std::isnan(corner_angle_weights[0]) || std::isnan(corner_angle_weights[1])) {
         freeBindData(bwdata);
         data->success = MOD_SDEF_BIND_RESULT_GENERIC_ERR;
         return nullptr;
