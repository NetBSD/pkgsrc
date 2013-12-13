$NetBSD: patch-src_gdiplus-private.h,v 1.1 2013/12/13 20:50:05 markd Exp $

Build with freetype 2.5.x

--- src/gdiplus-private.h.orig	2011-01-13 22:28:19.000000000 +0000
+++ src/gdiplus-private.h
@@ -30,7 +30,8 @@
 #include <stdio.h>
 #include <math.h>
 #include <glib.h>
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 #include <pthread.h>
 #include <unistd.h>
 
