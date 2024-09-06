$NetBSD: patch-source_blender_editors_interface_interface__draw.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

LHS gets promoted to double, and min expects both arguments to have
the same type.

--- source/blender/editors/interface/interface_draw.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/interface/interface_draw.cc
@@ -1241,8 +1241,10 @@ static void ui_draw_colorband_handle(uin
   GPU_blend(GPU_BLEND_ALPHA);
 
   /* Allow the lines to decrease as we get really small. */
-  float line_width = std::max(std::min(U.pixelsize / 5.0f * fabs(half_width - 4.0f), U.pixelsize),
-                              0.5f);
+  float line_width = std::max(
+                       std::min(static_cast<float>(U.pixelsize / 5.0f * fabs(half_width - 4.0f)), U.pixelsize),
+                       0.5f
+                     );
 
   /* Make things transparent as we get tiny. */
   uchar alpha = std::min(int(fabs(half_width - 2.0f) * 50.0f), 255);
