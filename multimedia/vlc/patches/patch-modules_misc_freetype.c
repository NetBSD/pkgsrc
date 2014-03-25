$NetBSD: patch-modules_misc_freetype.c,v 1.1 2014/03/25 16:04:12 prlw1 Exp $

http://git.videolan.org/?p=vlc.git;a=commit;h=c5b2b0a284ba6b544646f3a205aa1a2e1117d431`

--- modules/misc/freetype.c.orig	2014-03-25 15:08:15.000000000 +0000
+++ modules/misc/freetype.c
@@ -60,9 +60,10 @@
 #endif
 
 /* Freetype */
-#include <freetype/ftsynth.h>
+#include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
+#include FT_SYNTHESIS_H
 #define FT_FLOOR(X)     ((X & -64) >> 6)
 #define FT_CEIL(X)      (((X + 63) & -64) >> 6)
 #ifndef FT_MulFix
