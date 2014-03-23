$NetBSD: patch-src_libpaps.c,v 1.1 2014/03/23 08:14:23 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- src/libpaps.c.orig	2007-01-19 11:17:11.000000000 +0000
+++ src/libpaps.c
@@ -25,8 +25,9 @@
 
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 #include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
