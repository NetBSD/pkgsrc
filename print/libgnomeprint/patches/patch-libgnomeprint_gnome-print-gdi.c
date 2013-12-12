$NetBSD: patch-libgnomeprint_gnome-print-gdi.c,v 1.1 2013/12/12 01:04:14 markd Exp $

Fix build with freetype 2.5.x 

--- libgnomeprint/gnome-print-gdi.c.orig	2010-02-09 12:32:51.000000000 +0000
+++ libgnomeprint/gnome-print-gdi.c
@@ -36,7 +36,7 @@
 #include <libgnomeprint/gp-gc-private.h>
 
 #include <ft2build.h>
-#include <freetype/freetype.h>
+#include FT_FREETYPE_H
 
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
