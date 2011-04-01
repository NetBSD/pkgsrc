$NetBSD: patch-x11_png.c,v 1.1 2011/04/01 15:31:33 wiz Exp $

Fix build with png-1.5.

--- x11/png.c.orig	2008-01-29 07:29:06.000000000 +0000
+++ x11/png.c
@@ -88,7 +88,7 @@ uint8 *png_to_data(unsigned char *data, 
 	png_destroy_read_struct (&png_ptr, NULL, NULL);
 	return NULL;
     }
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
 	return NULL;
     }
@@ -600,7 +600,7 @@ int png_to_xpixmap(Display *display, Dra
 	png_destroy_read_struct (&png_ptr, NULL, NULL);
 	return PNGX_OUTOFMEM;
     }
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
 	return PNGX_DATA;
     }
