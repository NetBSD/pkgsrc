$NetBSD: patch-render.c,v 1.1 2016/02/14 14:01:49 leot Exp $

Fix the colorspace.

--- render.c.orig	2015-12-22 22:38:09.000000000 +0000
+++ render.c
@@ -36,7 +36,7 @@ pdf_page_render_to_buffer(mupdf_document
   fz_irect irect = { .x1 = page_width, .y1 = page_height };
   fz_rect rect = { .x1 = page_width, .y1 = page_height };
 
-  fz_colorspace* colorspace = fz_device_rgb(mupdf_document->ctx);
+  fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
   fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
