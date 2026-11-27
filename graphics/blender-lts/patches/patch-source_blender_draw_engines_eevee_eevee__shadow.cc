$NetBSD: patch-source_blender_draw_engines_eevee_eevee__shadow.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/draw/engines/eevee/eevee_shadow.cc.orig	2026-08-26 12:56:59.645465499 +0000
+++ source/blender/draw/engines/eevee/eevee_shadow.cc
@@ -411,7 +411,7 @@ IndexRange ShadowDirectional::clipmap_level_range(cons
   using namespace blender::math;
   /* Covers the closest points of the view. */
   /* FIXME: IndexRange does not support negative indices. Clamp to 0 for now. */
-  int min_level = max(0.0f, floor(log2(abs(cam.data_get().clip_near))));
+  int min_level = max(0.0, floor(log2(abs(cam.data_get().clip_near))));
   /* Covers the farthest points of the view. */
   int max_level = ceil(log2(cam.bound_radius() + distance(cam.bound_center(), cam.position())));
   /* We actually need to cover a bit more because of clipmap origin snapping. */
