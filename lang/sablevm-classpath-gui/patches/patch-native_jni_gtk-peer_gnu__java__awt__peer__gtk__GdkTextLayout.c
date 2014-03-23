$NetBSD: patch-native_jni_gtk-peer_gnu__java__awt__peer__gtk__GdkTextLayout.c,v 1.1 2014/03/23 11:14:46 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c.orig	2005-12-07 17:54:35.000000000 +0000
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c
@@ -42,8 +42,9 @@
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
 #include <pango/pangofc-font.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 #include "native_state.h"
 #include "gdkfont.h"
 #include "gnu_java_awt_peer_gtk_GdkTextLayout.h"
