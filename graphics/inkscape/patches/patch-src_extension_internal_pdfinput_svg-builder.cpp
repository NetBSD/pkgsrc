$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.cpp,v 1.10 2024/03/11 21:19:39 wiz Exp $

Fix build with poppler-24.03.0.
https://gitlab.com/a17r/inkscape/-/commit/394c0d2a14816c1de6d34b4d505a6b5f612edc1a

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2023-11-16 19:05:21.000000000 +0000
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -1158,9 +1158,9 @@ static bool svgGetShadingColor(GfxShadin
 #define INT_EPSILON 8
 bool SvgBuilder::_addGradientStops(Inkscape::XML::Node *gradient, GfxShading *shading,
                                    _POPPLER_CONST Function *func) {
-    int type = func->getType();
+    auto type = func->getType();
     auto space = shading->getColorSpace();
-    if ( type == 0 || type == 2 ) {  // Sampled or exponential function
+    if (type == _POPPLER_TYPE_SAMPLED || type == _POPPLER_TYPE_EXPONENTIAL) {
         GfxColor stop1, stop2;
         if (!svgGetShadingColor(shading, 0.0, &stop1) || !svgGetShadingColor(shading, 1.0, &stop2)) {
             return false;
@@ -1168,7 +1168,7 @@ bool SvgBuilder::_addGradientStops(Inksc
             _addStopToGradient(gradient, 0.0, &stop1, space, 1.0);
             _addStopToGradient(gradient, 1.0, &stop2, space, 1.0);
         }
-    } else if ( type == 3 ) { // Stitching
+    } else if (type == _POPPLER_TYPE_STITCHING) {
         auto stitchingFunc = static_cast<_POPPLER_CONST StitchingFunction*>(func);
         const double *bounds = stitchingFunc->getBounds();
         const double *encode = stitchingFunc->getEncode();
@@ -1183,7 +1183,7 @@ bool SvgBuilder::_addGradientStops(Inksc
         for ( int i = 0 ; i < num_funcs ; i++ ) {
             svgGetShadingColor(shading, bounds[i + 1], &color);
             // Add stops
-            if (stitchingFunc->getFunc(i)->getType() == 2) {    // process exponential fxn
+            if (stitchingFunc->getFunc(i)->getType() == _POPPLER_TYPE_EXPONENTIAL) {
                 double expE = (static_cast<_POPPLER_CONST ExponentialFunction*>(stitchingFunc->getFunc(i)))->getE();
                 if (expE > 1.0) {
                     expE = (bounds[i + 1] - bounds[i])/expE;    // approximate exponential as a single straight line at x=1
