$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.cpp,v 1.1 2018/05/01 06:17:11 wiz Exp $

Support poppler-0.64.0.

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -1020,7 +1020,7 @@ void SvgBuilder::updateFont(GfxState *st
     GfxFont *font = state->getFont();
     // Store original name
     if (font->getName()) {
-        _font_specification = font->getName()->getCString();
+        _font_specification = (char*)font->getName()->getCString();
     } else {
         _font_specification = (char*) "Arial";
     }
