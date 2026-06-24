$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.h,v 1.5 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/svg-builder.h.orig	2025-12-13 00:49:29.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.h
@@ -186,7 +186,7 @@ class SvgBuilder { (private)
     // Pattern creation
     gchar *_createPattern(GfxPattern *pattern, GfxState *state, bool is_stroke=false);
     gchar *_createGradient(GfxShading *shading, const Geom::Affine pat_matrix, bool for_shading = false);
-    void _addStopToGradient(Inkscape::XML::Node *gradient, double offset, GfxColor *color, GfxColorSpace *space,
+    void _addStopToGradient(Inkscape::XML::Node *gradient, double offset, GfxColor &color, GfxColorSpace *space,
                             double opacity);
     bool _addGradientStops(Inkscape::XML::Node *gradient, GfxShading *shading,
                            _POPPLER_CONST Function *func);
@@ -239,6 +239,7 @@ class SvgBuilder { (private)
     static bool _attrEqual(Inkscape::XML::Node *a, Inkscape::XML::Node *b, char const *attr);
 
     // Colors
+    std::string convertGfxColor(const GfxColor &color, GfxColorSpace *space);
     std::string convertGfxColor(const GfxColor *color, GfxColorSpace *space);
     std::string _getColorProfile(cmsHPROFILE hp);
 
