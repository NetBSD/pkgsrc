$NetBSD: patch-source_blender_blenkernel_intern_object.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/blenkernel/intern/object.cc.orig	2022-11-04 03:58:17.000000000 +0000
+++ source/blender/blenkernel/intern/object.cc
@@ -3844,13 +3844,13 @@ void BKE_object_dimensions_set_ex(Object
 
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
