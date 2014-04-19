$NetBSD: patch-libraries_javalib_external_classpath_native_jni_gtk-peer_gnu__java__awt__peer__gtk__GdkTextLayout.c,v 1.1 2014/04/19 15:00:52 joerg Exp $

--- libraries/javalib/external/classpath/native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c.orig	2014-04-19 13:51:07.000000000 +0000
+++ libraries/javalib/external/classpath/native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c
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
