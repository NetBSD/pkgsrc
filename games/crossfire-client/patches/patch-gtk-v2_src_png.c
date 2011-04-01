$NetBSD: patch-gtk-v2_src_png.c,v 1.1 2011/04/01 15:31:33 wiz Exp $

Fix build with png-1.5.

--- gtk-v2/src/png.c.orig	2008-01-29 07:29:07.000000000 +0000
+++ gtk-v2/src/png.c
@@ -532,7 +532,7 @@ int png_to_gdkpixmap(GdkWindow *window, 
 	png_destroy_read_struct (&png_ptr, NULL, NULL);
 	return PNGX_OUTOFMEM;
     }
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct (&png_ptr, &info_ptr,NULL);
 	return PNGX_DATA;
     }
