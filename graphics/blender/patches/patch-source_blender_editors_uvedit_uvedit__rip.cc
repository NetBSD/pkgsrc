$NetBSD: patch-source_blender_editors_uvedit_uvedit__rip.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/uvedit/uvedit_rip.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/uvedit/uvedit_rip.cc
@@ -483,7 +483,7 @@ static float uv_rip_pairs_calc_uv_angle(
           dir_prev[1] /= aspect_y;
           dir_next[1] /= aspect_y;
           const float luv_angle = angle_v2v2(dir_prev, dir_next);
-          if (LIKELY(isfinite(luv_angle))) {
+          if (LIKELY(std::isfinite(luv_angle))) {
             angle_of_side += luv_angle;
           }
         }
