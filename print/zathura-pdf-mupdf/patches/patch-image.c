$NetBSD: patch-image.c,v 1.2 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- image.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ image.c
@@ -93,7 +93,7 @@ pdf_page_image_get_cairo(zathura_page_t*
   fz_pixmap* pixmap = NULL;
   cairo_surface_t* surface = NULL;
 
-  pixmap = fz_new_pixmap_from_image(mupdf_page->ctx, mupdf_image, 0, 0);
+  pixmap = fz_get_pixmap_from_image(mupdf_page->ctx, mupdf_image, NULL, NULL, NULL, NULL);
   if (pixmap == NULL) {
     goto error_free;
   }
