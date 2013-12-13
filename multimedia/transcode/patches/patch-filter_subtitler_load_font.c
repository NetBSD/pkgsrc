$NetBSD: patch-filter_subtitler_load_font.c,v 1.1 2013/12/13 20:54:03 markd Exp $

Build with freetype 2.5.x

--- filter/subtitler/load_font.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ filter/subtitler/load_font.c
@@ -48,7 +48,7 @@ Artur Zaprzala <zybi@fanthom.irc.pl>
 #include <ft2build.h>
 #include FT_FREETYPE_H
 
-#include <freetype/ftglyph.h>
+#include FT_GLYPH_H
 
 /**
  * @file bswap.h
