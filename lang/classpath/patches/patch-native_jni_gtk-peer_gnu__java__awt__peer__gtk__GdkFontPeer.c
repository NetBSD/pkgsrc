$NetBSD: patch-native_jni_gtk-peer_gnu__java__awt__peer__gtk__GdkFontPeer.c,v 1.2 2015/12/29 23:34:45 dholland Exp $

Include freetype headers according to the directions on the tin.

--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkFontPeer.c.orig	2014-04-19 12:54:37.000000000 +0000
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkFontPeer.c
@@ -38,10 +38,12 @@
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
 #include <pango/pangofc-font.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttypes.h>
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_TRUETYPE_TABLES_H
+#include FT_TYPES_H
+#include FT_OUTLINE_H
 #include "gdkfont.h"
 #include "gnu_java_awt_peer_gtk_GdkFontPeer.h"
 
