$NetBSD: patch-source_blender_blenlib_intern_convexhull__2d.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- source/blender/blenlib/intern/convexhull_2d.cc.orig	2026-09-13 05:51:18.640311190 +0000
+++ source/blender/blenlib/intern/convexhull_2d.cc
@@ -791,7 +791,7 @@ static float convexhull_aabb_fit_hull_2d(const float (
   }
 
   const float angle = (area_best != std::numeric_limits<float>::max()) ?
-                          atan2(sincos_best[0], sincos_best[1]) :
+                          std::atan2(sincos_best[0], sincos_best[1]) :
                           0.0f;
 
 #if defined(USE_BRUTE_FORCE_ASSERT) && !defined(NDEBUG)
