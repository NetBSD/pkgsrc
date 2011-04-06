$NetBSD: patch-src_ui__pixbuf__save.c,v 1.1.2.2 2011/04/06 22:17:40 tron Exp $

Fix build with png-1.5.

--- src/ui_pixbuf_save.c.orig	2004-04-02 14:22:33.000000000 +0000
+++ src/ui_pixbuf_save.c
@@ -86,7 +86,7 @@ gboolean pixbuf_to_file_as_png (GdkPixbu
 	    	return FALSE;
 		}
 
-	if (setjmp (png_ptr->jmpbuf))
+	if (setjmp (png_jmpbuf(png_ptr)))
 		{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (handle);
