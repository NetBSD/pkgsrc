$NetBSD: patch-gtk_png.c,v 1.1 2011/04/01 15:31:33 wiz Exp $

Fix build with png-1.5.

--- gtk/png.c.orig	2008-01-29 07:29:04.000000000 +0000
+++ gtk/png.c
@@ -86,7 +86,7 @@ uint8 *png_to_data(uint8 *data, int len,
 	png_destroy_read_struct (&png_ptr, NULL, NULL);
 	return NULL;
     }
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
 	return NULL;
     }
