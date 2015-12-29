$NetBSD: patch-native_jni_gtk-peer_gnu__java__awt__peer__gtk__FreetypeGlyphVector.c,v 1.2 2015/12/29 23:34:45 dholland Exp $

Include freetype headers according to the directions on the tin.

--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_FreetypeGlyphVector.c.orig	2014-04-19 12:53:50.000000000 +0000
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_FreetypeGlyphVector.c
@@ -41,8 +41,9 @@ exception statement from your version. *
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
 #include "gnu_java_awt_peer_gtk_FreetypeGlyphVector.h"
