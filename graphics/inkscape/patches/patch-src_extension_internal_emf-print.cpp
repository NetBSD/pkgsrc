$NetBSD: patch-src_extension_internal_emf-print.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/extension/internal/emf-print.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/extension/internal/emf-print.cpp
@@ -664,7 +664,7 @@ int PrintEmf::create_pen(SPStyle const *
         Geom::Point p1(one * transform);
         Geom::Point p(p1 - p0);
 
-        double scale = sqrt((p[X] * p[X]) + (p[Y] * p[Y])) / sqrt(2);
+        double scale = std::sqrt((p[X] * p[X]) + (p[Y] * p[Y])) / std::sqrt(2);
 
         if (!style->stroke_width.computed) {
             return 0;   //if width is 0 do not (reset) the pen, it should already be NULL_PEN
