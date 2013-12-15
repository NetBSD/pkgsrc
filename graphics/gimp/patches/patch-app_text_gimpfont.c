$NetBSD: patch-app_text_gimpfont.c,v 1.1 2013/12/15 08:25:38 markd Exp $

Build with freetype 2.5.x

--- app/text/gimpfont.c.orig	2012-05-08 06:05:46.000000000 +0000
+++ app/text/gimpfont.c
@@ -27,7 +27,7 @@
 
 #define PANGO_ENABLE_ENGINE  1   /* Argh */
 #include <pango/pango-ot.h>
-#include <freetype/tttables.h>
+#include FT_TRUETYPE_TABLES_H
 
 #include "text-types.h"
 
