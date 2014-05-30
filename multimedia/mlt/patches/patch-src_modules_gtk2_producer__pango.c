$NetBSD: patch-src_modules_gtk2_producer__pango.c,v 1.1 2014/05/30 11:34:51 joerg Exp $

--- src/modules/gtk2/producer_pango.c.orig	2014-05-28 20:46:18.000000000 +0000
+++ src/modules/gtk2/producer_pango.c
@@ -25,7 +25,8 @@
 #include <string.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <pango/pangoft2.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <iconv.h>
 #include <pthread.h>
 #include <ctype.h>
