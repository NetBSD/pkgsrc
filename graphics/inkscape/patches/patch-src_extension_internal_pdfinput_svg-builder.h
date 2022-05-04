$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.h,v 1.3 2022/05/04 21:13:52 wiz Exp $

Fix build with poppler-22.4.0
https://gitlab.com/inkscape/inkscape/-/issues/3387

--- src/extension/internal/pdfinput/svg-builder.h.orig	2022-02-05 01:21:47.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.h
@@ -203,7 +203,6 @@ private:
     std::vector<SvgGraphicsState> _state_stack;
 
     SPCSSAttr *_font_style;          // Current font style
-    GfxFont *_current_font;
     const char *_font_specification;
     double _font_scaling;
     bool _need_font_update;
