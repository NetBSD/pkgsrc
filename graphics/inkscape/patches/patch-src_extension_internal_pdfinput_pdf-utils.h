$NetBSD: patch-src_extension_internal_pdfinput_pdf-utils.h,v 1.1 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/pdf-utils.h.orig	2025-12-13 00:49:29.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-utils.h
@@ -59,6 +59,9 @@ Geom::Rect getRect(_POPPLER_CONST PDFRectangle *box);
 };
 
 Geom::Rect getRect(_POPPLER_CONST PDFRectangle *box);
+Geom::Rect getRect(_POPPLER_CONST PDFRectangle &box);
 Geom::PathVector getPathV(GfxPath *gPath);
+Geom::PathVector maybeIntersect(Geom::PathVector const &v1, Geom::PathVector const &v2,
+                                FillRule fill1 = FillRule::fill_nonZero, FillRule fill2 = FillRule::fill_nonZero);
 
 #endif /* PDF_UTILS_H */
