$NetBSD: patch-src_extension_internal_pdfinput_svg-builder.cpp,v 1.4 2020/01/11 09:59:06 martin Exp $

Add const casts for GfxPath.

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2019-01-15 05:29:27.000000000 +0100
+++ src/extension/internal/pdfinput/svg-builder.cpp	2020-01-11 10:25:56.021965309 +0100
@@ -441,7 +441,7 @@
  */
 void SvgBuilder::addPath(GfxState *state, bool fill, bool stroke, bool even_odd) {
     Inkscape::XML::Node *path = _xml_doc->createElement("svg:path");
-    gchar *pathtext = svgInterpretPath(state->getPath());
+    gchar *pathtext = svgInterpretPath(const_cast<GfxPath*>(state->getPath()));
     path->setAttribute("d", pathtext);
     g_free(pathtext);
 
@@ -528,7 +528,7 @@
     clip_path->setAttribute("clipPathUnits", "userSpaceOnUse");
     // Create the path
     Inkscape::XML::Node *path = _xml_doc->createElement("svg:path");
-    gchar *pathtext = svgInterpretPath(state->getPath());
+    gchar *pathtext = svgInterpretPath(const_cast<GfxPath*>(state->getPath()));
     path->setAttribute("d", pathtext);
     g_free(pathtext);
     if (even_odd) {
