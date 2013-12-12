$NetBSD: patch-libgnomeprint_gnome-font-face.c,v 1.1 2013/12/12 01:04:14 markd Exp $

Fix build with freetype 2.5.x

--- libgnomeprint/gnome-font-face.c.orig	2010-02-09 12:32:51.000000000 +0000
+++ libgnomeprint/gnome-font-face.c
@@ -36,7 +36,8 @@
 #include <stdarg.h>
 #include <locale.h>
 
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
 
 #include <libgnomeprint/gnome-print-private.h>
 #include <libgnomeprint/gnome-font-private.h>
