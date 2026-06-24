$NetBSD: patch-src_extension_internal_pdfinput_poppler-transition-api.h,v 1.9 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2026-04-23 22:59:59.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -15,6 +15,22 @@
 #include <glib/poppler-features.h>
 #include <poppler/UTF.h>
 
+#if POPPLER_CHECK_VERSION(26, 6, 0)
+#define _POPPLER_GET_GRAY(color, gray) getGray(color, gray)
+#define _POPPLER_GET_RGB(color, rgb) getRGB(color, rgb)
+#define _POPPLER_GET_CMYK(color, cmyk) getCMYK(color, cmyk)
+#define _POPPLER_SET_FILL_COLOR(color) setFillColor(color)
+#define _POPPLER_SET_STROKE_COLOR(color) setStrokeColor(color)
+#define _POPPLER_GFX_STATE(h, v, Rect, rotateA, upsideDown) GfxState(h, v, Rect, rotateA, upsideDown)
+#else
+#define _POPPLER_GET_GRAY(color, gray) getGray(&color, gray)
+#define _POPPLER_GET_RGB(color, rgb) getRGB(&color, rgb)
+#define _POPPLER_GET_CMYK(color, cmyk) getCMYK(&color, cmyk)
+#define _POPPLER_SET_FILL_COLOR(color) setFillColor(&color)
+#define _POPPLER_SET_STROKE_COLOR(color) setStrokeColor(&color)
+#define _POPPLER_GFX_STATE(h, v, Rect, rotateA, upsideDown) GfxState(h, v, &Rect, rotateA, upsideDown)
+#endif
+
 #if POPPLER_CHECK_VERSION(26, 2, 0)
 #define _POPPLER_WMODE GfxFont::WritingMode
 #define _POPPLER_WMODE_HORIZONTAL GfxFont::WritingMode::Horizontal
