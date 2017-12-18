$NetBSD: patch-render.c,v 1.5 2017/12/18 15:07:14 leot Exp $

- Close device.

  Every fz_drop_device() need a corresponding fz_close_device().
  
  This fixes the:
  
   warning: dropping unclosed device
   warning: ... repeated <n> times ..
  
  warnings.

  Backport from upstream, commit 622b35440d708a187add31adab8bca747c11d2a8.
  
- Updated for MuPDF 1.12.0
  
  Backport from upstream, commit a3f703788f77b19bb986e14666fe0c47911adddc.

--- render.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ render.c
@@ -31,21 +31,25 @@ pdf_page_render_to_buffer(mupdf_document
     return ZATHURA_ERROR_UNKNOWN;
   }
 
+  fz_close_device(mupdf_page->ctx, device);
   fz_drop_device(mupdf_page->ctx, device);
 
   fz_irect irect = { .x1 = page_width, .y1 = page_height };
   fz_rect rect = { .x1 = page_width, .y1 = page_height };
 
   fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
-  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, 1, image);
+  fz_separations* seps= fz_page_separations(mupdf_page->ctx, mupdf_page->page);
+  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, seps, 1, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
   device = fz_new_draw_device(mupdf_page->ctx, NULL, pixmap);
   fz_run_display_list(mupdf_page->ctx, display_list, device, &fz_identity, &rect, NULL);
+  fz_close_device(mupdf_page->ctx, device);
   fz_drop_device(mupdf_page->ctx, device);
 
   fz_drop_pixmap(mupdf_page->ctx, pixmap);
   fz_drop_display_list(mupdf_page->ctx, display_list);
+  fz_drop_separations(mupdf_page->ctx, seps);
 
   return ZATHURA_ERROR_OK;
 }
