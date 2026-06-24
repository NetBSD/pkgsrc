$NetBSD: patch-src_extension_internal_pdfinput_pdf-utils.cpp,v 1.1 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/pdf-utils.cpp.orig	2025-12-13 00:49:29.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-utils.cpp
@@ -133,6 +133,11 @@ Geom::Rect getRect(_POPPLER_CONST PDFRectangle *box)
     return Geom::Rect(box->x1, box->y1, box->x2, box->y2);
 }
 
+Geom::Rect getRect(const PDFRectangle &box)
+{
+    return Geom::Rect(box.x1, box.y1, box.x2, box.y2);
+}
+
 Geom::PathVector getPathV(GfxPath *path) 
 {
     if (!path) {
