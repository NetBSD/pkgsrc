$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.cpp,v 1.6 2022/05/04 21:13:52 wiz Exp $

Fix build with poppler-22.4.0
https://gitlab.com/inkscape/inkscape/-/issues/3387

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2022-02-05 01:21:47.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -108,7 +108,6 @@ SvgBuilder::~SvgBuilder() = default;
 
 void SvgBuilder::_init() {
     _font_style = nullptr;
-    _current_font = nullptr;
     _font_specification = nullptr;
     _font_scaling = 1;
     _need_font_update = true;
@@ -1021,11 +1020,8 @@ void SvgBuilder::updateFont(GfxState *st
     _need_font_update = false;
     updateTextMatrix(state);    // Ensure that we have a text matrix built
 
-    if (_font_style) {
-        //sp_repr_css_attr_unref(_font_style);
-    }
     _font_style = sp_repr_css_attr_new();
-    GfxFont *font = state->getFont();
+    auto font = state->getFont();
     // Store original name
     if (font->getName()) {
         _font_specification = font->getName()->getCString();
@@ -1171,7 +1167,6 @@ void SvgBuilder::updateFont(GfxState *st
         sp_repr_css_set_property(_font_style, "writing-mode", "tb");
     }
 
-    _current_font = font;
     _invalidated_style = true;
 }
 
