$NetBSD: patch-render.c,v 1.3 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- render.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ render.c
@@ -20,7 +20,10 @@ pdf_page_render_to_buffer(mupdf_document
     return ZATHURA_ERROR_UNKNOWN;
   }
 
-  fz_display_list* display_list = fz_new_display_list(mupdf_page->ctx);
+  fz_irect irect = { .x1 = page_width, .y1 = page_height };
+  fz_rect rect = { .x1 = page_width, .y1 = page_height };
+
+  fz_display_list* display_list = fz_new_display_list(mupdf_page->ctx, &rect);
   fz_device* device             = fz_new_list_device(mupdf_page->ctx, display_list);
 
   fz_try (mupdf_document->ctx) {
@@ -33,14 +36,11 @@ pdf_page_render_to_buffer(mupdf_document
 
   fz_drop_device(mupdf_page->ctx, device);
 
-  fz_irect irect = { .x1 = page_width, .y1 = page_height };
-  fz_rect rect = { .x1 = page_width, .y1 = page_height };
-
   fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
-  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, image);
+  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, 1, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
-  device = fz_new_draw_device(mupdf_page->ctx, pixmap);
+  device = fz_new_draw_device(mupdf_page->ctx, NULL, pixmap);
   fz_run_display_list(mupdf_page->ctx, display_list, device, &fz_identity, &rect, NULL);
   fz_drop_device(mupdf_page->ctx, device);
 
