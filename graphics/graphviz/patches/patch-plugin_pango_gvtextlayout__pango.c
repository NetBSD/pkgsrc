$NetBSD: patch-plugin_pango_gvtextlayout__pango.c,v 1.1 2019/08/17 00:11:32 ryoon Exp $

* For FT_Face etc. not found errors

--- plugin/pango/gvtextlayout_pango.c.orig	2016-09-20 04:45:02.000000000 +0000
+++ plugin/pango/gvtextlayout_pango.c
@@ -24,6 +24,8 @@
 #include <pango/pangocairo.h>
 #include "gvgetfontlist.h"
 #ifdef HAVE_PANGO_FC_FONT_LOCK_FACE
+#include <ft2build.h>
+#include <freetype/freetype.h>
 #include <pango/pangofc-font.h>
 #endif
 
