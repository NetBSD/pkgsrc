$NetBSD: patch-src_display_cairo-utils.cpp,v 1.2 2021/07/02 14:04:06 wiz Exp $

Fix isnan() not defined.
https://gitlab.com/inkscape/inkscape/-/merge_requests/3376

--- src/display/cairo-utils.cpp.orig	2021-05-17 19:26:40.000000000 +0000
+++ src/display/cairo-utils.cpp
@@ -772,7 +772,7 @@ feed_curve_to_cairo(cairo_t *cr, Geom::C
             } else {
                 Geom::Affine xform = arc->unitCircleTransform() * trans;
                 // Don't draw anything if the angle is borked
-                if(isnan(arc->initialAngle()) || isnan(arc->finalAngle())) {
+                if(std::isnan(arc->initialAngle()) || std::isnan(arc->finalAngle())) {
                     g_warning("Bad angle while drawing EllipticalArc");
                     break;
                 }
