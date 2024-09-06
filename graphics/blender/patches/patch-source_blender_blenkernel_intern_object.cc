$NetBSD: patch-source_blender_blenkernel_intern_object.cc,v 1.2 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/object.cc.orig	2024-08-06 17:21:03.000000000 +0000
+++ source/blender/blenkernel/intern/object.cc
@@ -3657,13 +3657,13 @@ void BKE_object_dimensions_set_ex(Object
 
         if (ob_scale_orig != nullptr) {
           const float scale_delta = len_v3(ob_obmat_orig[i]) / ob_scale_orig[i];
-          if (isfinite(scale_delta)) {
+          if (std::isfinite(scale_delta)) {
             len[i] *= scale_delta;
           }
         }
 
         const float scale = copysignf(value[i] / len[i], ob->scale[i]);
-        if (isfinite(scale)) {
+        if (std::isfinite(scale)) {
           ob->scale[i] = scale;
         }
       }
