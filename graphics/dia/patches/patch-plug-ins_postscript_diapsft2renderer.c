$NetBSD: patch-plug-ins_postscript_diapsft2renderer.c,v 1.1 2014/03/23 09:07:15 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- plug-ins/postscript/diapsft2renderer.c.orig	2009-11-07 17:13:53.000000000 +0000
+++ plug-ins/postscript/diapsft2renderer.c
@@ -29,8 +29,9 @@
 #include <pango/pangoft2.h>
 #include <pango/pango-engine.h>
 /* I'd really rather avoid this */
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 
 #define DPI 300
 
