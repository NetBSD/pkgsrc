$NetBSD: patch-source_blender_editors_transform_transform__convert__mesh.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/transform/transform_convert_mesh.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/transform/transform_convert_mesh.cc
@@ -605,7 +605,7 @@ static void mesh_customdatacorrect_apply
             v->co, UNPACK3(v_proj), v_proj_axis);
 
         loop_weights[j] = (dist >= 0.0f) ? 1.0f : ((dist <= -eps) ? 0.0f : (1.0f + (dist / eps)));
-        if (UNLIKELY(!isfinite(loop_weights[j]))) {
+        if (UNLIKELY(!std::isfinite(loop_weights[j]))) {
           loop_weights[j] = 0.0f;
         }
       }
