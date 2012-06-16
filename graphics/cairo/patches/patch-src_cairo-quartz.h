$NetBSD: patch-src_cairo-quartz.h,v 1.1 2012/06/16 20:52:18 tron Exp $

Fix 32 bit build under Mac OS X Lion. Patch taken from here:

http://cgit.freedesktop.org/cairo/commit/?id=8664df767cb9dbe48647f9853e3dcf551701d3ca

--- src/cairo-quartz.h.orig	2010-06-18 12:47:13.000000000 +0100
+++ src/cairo-quartz.h	2012-06-16 21:46:19.000000000 +0100
@@ -66,10 +66,8 @@
 cairo_public cairo_font_face_t *
 cairo_quartz_font_face_create_for_cgfont (CGFontRef font);
 
-#ifndef __LP64__
 cairo_public cairo_font_face_t *
 cairo_quartz_font_face_create_for_atsu_font_id (ATSUFontID font_id);
-#endif
 
 #endif /* CAIRO_HAS_QUARTZ_FONT */
 
