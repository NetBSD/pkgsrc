$NetBSD: patch-libgnomeprint_gnome-rfont.c,v 1.1 2013/12/12 01:04:14 markd Exp $

Fix build with freetype 2.5.x 

--- libgnomeprint/gnome-rfont.c.orig	2010-02-09 12:32:51.000000000 +0000
+++ libgnomeprint/gnome-rfont.c
@@ -28,8 +28,8 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H
-#include <freetype/ftglyph.h>
-#include <freetype/ftbbox.h>
+#include FT_GLYPH_H
+#include FT_BBOX_H
 #include <libart_lgpl/art_misc.h>
 #include <libart_lgpl/art_affine.h>
 #include <libart_lgpl/art_vpath.h>
