$NetBSD: patch-source_blender_editors_transform_transform__constraints.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/transform/transform_constraints.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/transform/transform_constraints.cc
@@ -253,13 +253,13 @@ static void axisProjection(const TransIn
       }
 
       /* Possible some values become nan when viewpoint and object are both zero. */
-      if (!isfinite(out[0])) {
+      if (!std::isfinite(out[0])) {
         out[0] = 0.0f;
       }
-      if (!isfinite(out[1])) {
+      if (!std::isfinite(out[1])) {
         out[1] = 0.0f;
       }
-      if (!isfinite(out[2])) {
+      if (!std::isfinite(out[2])) {
         out[2] = 0.0f;
       }
     }
