$NetBSD: patch-gfx_thebes_src_gfxPangoFonts.cpp,v 1.1 2014/04/03 10:52:13 wiz Exp $

Fix build with freetype-2.5.1.

--- gfx/thebes/src/gfxPangoFonts.cpp.orig	2012-03-06 14:45:28.000000000 +0000
+++ gfx/thebes/src/gfxPangoFonts.cpp
@@ -61,7 +61,8 @@
 #include "gfxFontconfigUtils.h"
 #include "gfxUserFontSet.h"
 
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 
 #include <cairo.h>
 #include <cairo-ft.h>
