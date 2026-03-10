$NetBSD: patch-src_hb-raster-svg-parse.cc,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-raster-svg-parse.cc.orig	2026-03-09 18:03:02.855356965 +0000
+++ src/hb-raster-svg-parse.cc
@@ -216,7 +216,7 @@ svg_arc_endpoint_to_center (float x1, float y1, float 
   auto angle = [] (float ux, float uy, float vx, float vy) -> float {
     float dot = ux * vx + uy * vy;
     float len = sqrtf ((ux * ux + uy * uy) * (vx * vx + vy * vy));
-    if (!(len > 0.f) || !isfinite (len))
+    if (!(len > 0.f) || !std::isfinite (len))
       return 0.f;
     float a = acosf (hb_clamp (dot / len, -1.f, 1.f));
     if (ux * vy - uy * vx < 0.f) a = -a;
