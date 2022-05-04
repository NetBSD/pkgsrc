$NetBSD: patch-src_extension_internal_pdfinput_poppler-transition-api.h,v 1.3 2022/05/04 21:13:52 wiz Exp $

Fix build with poppler-22.4.0
https://gitlab.com/inkscape/inkscape/-/issues/3387

--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2022-02-05 01:12:19.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -14,6 +14,12 @@
 
 #include <glib/poppler-features.h>
 
+#if POPPLER_CHECK_VERSION(22, 4, 0)
+#define _POPPLER_FONTPTR_TO_GFX8(font_ptr) ((Gfx8BitFont *)font_ptr.get())
+#else
+#define _POPPLER_FONTPTR_TO_GFX8(font_ptr) ((Gfx8BitFont *)font_ptr)
+#endif
+
 #if POPPLER_CHECK_VERSION(0, 83, 0)
 #define _POPPLER_CONST_83 const
 #else
