$NetBSD: patch-source_blender_draw_engines_eevee__next_eevee__shadow.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/draw/engines/eevee_next/eevee_shadow.cc.orig	2024-08-06 17:21:03.000000000 +0000
+++ source/blender/draw/engines/eevee_next/eevee_shadow.cc
@@ -398,7 +398,7 @@ IndexRange ShadowDirectional::clipmap_le
   using namespace blender::math;
   /* Covers the closest points of the view. */
   /* FIXME: IndexRange does not support negative indices. Clamp to 0 for now. */
-  int min_level = max(0.0f, floor(log2(abs(cam.data_get().clip_near))));
+  int min_level = max(0.0f, static_cast<float>(floor(log2(abs(cam.data_get().clip_near)))));
   /* Covers the farthest points of the view. */
   int max_level = ceil(log2(cam.bound_radius() + distance(cam.bound_center(), cam.position())));
   /* We actually need to cover a bit more because of clipmap origin snapping. */
