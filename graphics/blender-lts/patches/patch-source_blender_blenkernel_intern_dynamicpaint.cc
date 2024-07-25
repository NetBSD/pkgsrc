$NetBSD: patch-source_blender_blenkernel_intern_dynamicpaint.cc,v 1.1 2024/07/25 06:00:38 ryoon Exp $

--- source/blender/blenkernel/intern/dynamicpaint.cc.orig	2024-07-02 09:50:56.955643689 +0000
+++ source/blender/blenkernel/intern/dynamicpaint.cc
@@ -4609,7 +4609,7 @@ static bool dynamicPaint_paintParticles(
 
     /* for debug purposes check if any NAN particle proceeds
      * For some reason they get past activity check, this should rule most of them out */
-    if (isnan(pa->state.co[0]) || isnan(pa->state.co[1]) || isnan(pa->state.co[2])) {
+    if (std::isnan(pa->state.co[0]) || std::isnan(pa->state.co[1]) || std::isnan(pa->state.co[2])) {
       invalidParticles++;
       continue;
     }
