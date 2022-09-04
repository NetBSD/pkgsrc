$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.cpp,v 1.8 2022/09/04 07:55:02 martin Exp $

Adapt to new poppler API

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2022-05-07 15:43:15.000000000 +0200
+++ src/extension/internal/pdfinput/svg-builder.cpp	2022-09-04 09:46:02.599786816 +0200
@@ -388,15 +388,13 @@ void SvgBuilder::_setStrokeStyle(SPCSSAt
     sp_repr_css_set_property(css, "stroke-miterlimit", os_ml.str().c_str());
 
     // Line dash
-    double *dash_pattern;
-    int dash_length;
     double dash_start;
-    state->getLineDash(&dash_pattern, &dash_length, &dash_start);
-    if ( dash_length > 0 ) {
+    auto dash_pattern = state->getLineDash(&dash_start);
+    if ( !dash_pattern.empty() ) {
         Inkscape::CSSOStringStream os_array;
-        for ( int i = 0 ; i < dash_length ; i++ ) {
+        for ( size_t i = 0; i < dash_pattern.size(); i++ ) {
             os_array << dash_pattern[i];
-            if (i < (dash_length - 1)) {
+            if (i < (dash_pattern.size() - 1)) {
                 os_array << ",";
             }
         }
