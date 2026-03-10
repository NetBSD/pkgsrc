$NetBSD: patch-src_hb-raster-svg-fill.cc,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-raster-svg-fill.cc.orig	2026-03-09 18:02:43.345394456 +0000
+++ src/hb-raster-svg-fill.cc
@@ -224,7 +224,7 @@ hb_raster_svg_emit_fill (const hb_svg_fill_context_t *
     {
       float w = object_bbox->xmax - object_bbox->xmin;
       float h = object_bbox->ymax - object_bbox->ymin;
-      if (isfinite (w) && isfinite (h) && w > 0.f && h > 0.f)
+      if (std::isfinite (w) && std::isfinite (h) && w > 0.f && h > 0.f)
         hb_paint_push_transform (ctx->pfuncs, ctx->paint, w, 0, 0, h, object_bbox->xmin, object_bbox->ymin);
       else
         has_bbox_transform = false;
@@ -249,7 +249,7 @@ hb_raster_svg_emit_fill (const hb_svg_fill_context_t *
     }
     else
     {
-      if (!isfinite (effective.r) || effective.r < 0.f)
+      if (!std::isfinite (effective.r) || effective.r < 0.f)
       {
         if (effective.has_gradient_transform)
           hb_paint_pop_transform (ctx->pfuncs, ctx->paint);
@@ -263,7 +263,7 @@ hb_raster_svg_emit_fill (const hb_svg_fill_context_t *
       float fx = effective.has_fx ? effective.fx : effective.cx;
       float fy = effective.has_fy ? effective.fy : effective.cy;
       float fr = effective.has_fr ? effective.fr : 0.f;
-      if (!isfinite (fr) || fr < 0.f)
+      if (!std::isfinite (fr) || fr < 0.f)
         fr = 0.f;
       fr = hb_min (fr, effective.r);
 
