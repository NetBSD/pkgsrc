$NetBSD: patch-source_blender_draw_engines_eevee_eevee__shadow.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/draw/engines/eevee/eevee_shadow.cc.orig	2026-09-13 20:27:13.507532242 +0000
+++ source/blender/draw/engines/eevee/eevee_shadow.cc
@@ -414,7 +414,7 @@ IndexRange ShadowDirectional::clipmap_level_range(cons
   using namespace blender::math;
   /* Covers the closest points of the view. */
   /* FIXME: IndexRange does not support negative indices. Clamp to 0 for now. */
-  int min_level = max(0.0f, floor(log2(abs(cam.data_get().clip_near))));
+  int min_level = std::max(0.0f, std::floor(std::log2(std::abs(cam.data_get().clip_near))));
   /* Covers the farthest points of the view. */
   int max_level = ceil(log2(cam.bound_radius() + distance(cam.bound_center(), cam.position())));
   /* We actually need to cover a bit more because of clipmap origin snapping. */
