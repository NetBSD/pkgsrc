$NetBSD: patch-src_extension_internal_pdfinput_poppler-transition-api.h,v 1.5 2024/03/11 21:19:38 wiz Exp $

Fix build with poppler-24.03.0.
https://gitlab.com/a17r/inkscape/-/commit/394c0d2a14816c1de6d34b4d505a6b5f612edc1a

--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2022-04-05 19:25:39.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -14,6 +14,16 @@
 
 #include <glib/poppler-features.h>
 
+#if POPPLER_CHECK_VERSION(24, 3, 0)
+#define _POPPLER_TYPE_SAMPLED Function::Type::Sampled
+#define _POPPLER_TYPE_EXPONENTIAL Function::Type::Exponential
+#define _POPPLER_TYPE_STITCHING Function::Type::Stitching
+#else
+#define _POPPLER_TYPE_SAMPLED 0
+#define _POPPLER_TYPE_EXPONENTIAL 2
+#define _POPPLER_TYPE_STITCHING 3
+#endif
+
 #if POPPLER_CHECK_VERSION(22, 4, 0)
 #define _POPPLER_FONTPTR_TO_GFX8(font_ptr) ((Gfx8BitFont *)font_ptr.get())
 #else
