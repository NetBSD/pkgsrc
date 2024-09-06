$NetBSD: patch-source_blender_editors_transform_transform__mode__resize.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/transform/transform_mode_resize.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/transform/transform_mode_resize.cc
@@ -117,7 +117,7 @@ static void constrain_scale_to_boundary(
   }
 
   const float correction = numerator / denominator;
-  if (correction < 0.0f || !isfinite(correction)) {
+  if (correction < 0.0f || !std::isfinite(correction)) {
     /* TODO: Correction is negative or invalid, but we lack context to fix `*scale`. */
     return;
   }
