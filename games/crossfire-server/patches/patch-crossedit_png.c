$NetBSD: patch-crossedit_png.c,v 1.1 2011/04/01 15:21:50 wiz Exp $

Fix build with png-1.5.

--- crossedit/png.c.orig	2008-02-01 05:56:34.000000000 +0000
+++ crossedit/png.c
@@ -269,7 +269,7 @@ int png_to_xpixmap(Display *display, Dra
 	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
 	return PNGX_OUTOFMEM;
     }
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct (&png_ptr, &info_ptr, &end_info);
 	return PNGX_DATA;
     }
