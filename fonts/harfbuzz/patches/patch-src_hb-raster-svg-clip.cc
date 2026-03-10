$NetBSD: patch-src_hb-raster-svg-clip.cc,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-raster-svg-clip.cc.orig	2026-03-09 18:03:15.704619086 +0000
+++ src/hb-raster-svg-clip.cc
@@ -529,7 +529,7 @@ hb_raster_svg_push_clip_path_ref (hb_raster_paint_t *p
       return false;
     float w = object_bbox->xmax - object_bbox->xmin;
     float h = object_bbox->ymax - object_bbox->ymin;
-    if (!(isfinite (w) && isfinite (h)) || w <= 0.f || h <= 0.f)
+    if (!(std::isfinite (w) && std::isfinite (h)) || w <= 0.f || h <= 0.f)
       return false;
     ed.has_bbox_transform = true;
     ed.bbox_transform = hb_transform_t<> (w, 0, 0, h, object_bbox->xmin, object_bbox->ymin);
