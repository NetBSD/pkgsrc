$NetBSD: patch-modules_text__renderer_freetype.c,v 1.1 2015/10/25 10:52:24 wiz Exp $

Fix build with freetype-2.5.

--- modules/text_renderer/freetype.c.orig	2014-03-19 21:17:25.000000000 +0000
+++ modules/text_renderer/freetype.c
@@ -64,10 +64,11 @@
 #endif
 
 /* Freetype */
-#include <freetype/ftsynth.h>
+#include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 #include FT_STROKER_H
+#include FT_SYNTHESIS_H
 
 #define FT_FLOOR(X)     ((X & -64) >> 6)
 #define FT_CEIL(X)      (((X + 63) & -64) >> 6)
