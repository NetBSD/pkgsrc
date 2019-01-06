$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.h,v 1.1 2019/01/06 08:41:01 markd Exp $

support for poppler 0.72 from upstream by way of linuxfromscratch 

--- src/extension/internal/pdfinput/svg-builder.h.orig	2018-03-11 20:38:09.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.h
@@ -15,6 +15,7 @@
 #endif
 
 #ifdef HAVE_POPPLER
+#include "poppler-transition-api.h"
 
 class SPDocument;
 namespace Inkscape {
@@ -29,7 +30,6 @@ namespace Inkscape {
 #include <glibmm/ustring.h>
 
 #include "CharTypes.h"
-class GooString;
 class Function;
 class GfxState;
 struct GfxColor;
@@ -81,7 +81,7 @@ struct SvgGlyph {
     bool style_changed;  // Set to true if style has to be reset
     SPCSSAttr *style;
     int render_mode;    // Text render mode
-    char *font_specification;   // Pointer to current font specification
+    const char *font_specification;   // Pointer to current font specification
 };
 
 /**
@@ -136,7 +136,7 @@ public:
     void clearSoftMask(GfxState *state);
 
     // Text handling
-    void beginString(GfxState *state, GooString *s);
+    void beginString(GfxState *state);
     void endString(GfxState *state);
     void addChar(GfxState *state, double x, double y,
                  double dx, double dy,
@@ -175,7 +175,7 @@ private:
     void _addStopToGradient(Inkscape::XML::Node *gradient, double offset,
                             GfxRGB *color, double opacity);
     bool _addGradientStops(Inkscape::XML::Node *gradient, GfxShading *shading,
-                           Function *func);
+                           _POPPLER_CONST Function *func);
     gchar *_createTilingPattern(GfxTilingPattern *tiling_pattern, GfxState *state,
                                 bool is_stroke=false);
     // Image/mask creation
@@ -203,7 +203,7 @@ private:
 
     SPCSSAttr *_font_style;          // Current font style
     GfxFont *_current_font;
-    char *_font_specification;
+    const char *_font_specification;
     double _font_scaling;
     bool _need_font_update;
     Geom::Affine _text_matrix;
