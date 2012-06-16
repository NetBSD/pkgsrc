$NetBSD: patch-src_cairo-quartz-font.c,v 1.1 2012/06/16 20:52:18 tron Exp $

Fix 32 bit build under Mac OS X Lion. Patch taken from here:

http://cgit.freedesktop.org/cairo/commit/?id=8664df767cb9dbe48647f9853e3dcf551701d3ca

--- src/cairo-quartz-font.c.orig	2010-12-25 14:21:34.000000000 +0000
+++ src/cairo-quartz-font.c	2012-06-16 21:46:19.000000000 +0100
@@ -90,6 +90,9 @@
 static int (*CGFontGetDescentPtr) (CGFontRef fontRef) = NULL;
 static int (*CGFontGetLeadingPtr) (CGFontRef fontRef) = NULL;
 
+/* Not public anymore in 64-bits nor in 10.7 */
+static ATSFontRef (*FMGetATSFontRefFromFontPtr) (FMFont iFont) = NULL;
+
 static cairo_bool_t _cairo_quartz_font_symbol_lookup_done = FALSE;
 static cairo_bool_t _cairo_quartz_font_symbols_present = FALSE;
 
@@ -127,6 +130,8 @@
     CGContextGetAllowsFontSmoothingPtr = dlsym(RTLD_DEFAULT, "CGContextGetAllowsFontSmoothing");
     CGContextSetAllowsFontSmoothingPtr = dlsym(RTLD_DEFAULT, "CGContextSetAllowsFontSmoothing");
 
+    FMGetATSFontRefFromFontPtr = dlsym(RTLD_DEFAULT, "FMGetATSFontRefFromFont");
+
     if ((CGFontCreateWithFontNamePtr || CGFontCreateWithNamePtr) &&
 	CGFontGetGlyphBBoxesPtr &&
 	CGFontGetGlyphsForUnicharsPtr &&
@@ -777,7 +782,6 @@
     return ffont->cgFont;
 }
 
-#ifndef __LP64__
 /*
  * compat with old ATSUI backend
  */
@@ -798,15 +802,22 @@
 cairo_font_face_t *
 cairo_quartz_font_face_create_for_atsu_font_id (ATSUFontID font_id)
 {
-    ATSFontRef atsFont = FMGetATSFontRefFromFont (font_id);
-    CGFontRef cgFont = CGFontCreateWithPlatformFont (&atsFont);
-    cairo_font_face_t *ff;
+    quartz_font_ensure_symbols();
 
-    ff = cairo_quartz_font_face_create_for_cgfont (cgFont);
+    if (FMGetATSFontRefFromFontPtr != NULL) {
+	ATSFontRef atsFont = FMGetATSFontRefFromFontPtr (font_id);
+	CGFontRef cgFont = CGFontCreateWithPlatformFont (&atsFont);
+	cairo_font_face_t *ff;
 
-    CGFontRelease (cgFont);
+	ff = cairo_quartz_font_face_create_for_cgfont (cgFont);
+
+	CGFontRelease (cgFont);
 
-    return ff;
+	return ff;
+    } else {
+	_cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
+	return (cairo_font_face_t *)&_cairo_font_face_nil;
+    }
 }
 
 /* This is the old name for the above function, exported for compat purposes */
@@ -817,4 +828,3 @@
 {
     return cairo_quartz_font_face_create_for_atsu_font_id (font_id);
 }
-#endif
