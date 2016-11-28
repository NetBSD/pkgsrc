$NetBSD: patch-utils.c,v 1.2 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- utils.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ utils.c
@@ -14,7 +14,7 @@ mupdf_page_extract_text(mupdf_document_t
   fz_device* text_device = NULL;
 
   fz_try (mupdf_page->ctx) {
-    text_device = fz_new_text_device(mupdf_page->ctx, mupdf_page->sheet, mupdf_page->text);
+    text_device = fz_new_stext_device(mupdf_page->ctx, mupdf_page->sheet, mupdf_page->text, NULL);
 
     /* Disable FZ_IGNORE_IMAGE to collect image blocks */
     fz_disable_device_hints(mupdf_page->ctx, text_device, FZ_IGNORE_IMAGE);
@@ -23,6 +23,7 @@ mupdf_page_extract_text(mupdf_document_t
     fz_scale(&ctm, 1.0, 1.0);
     fz_run_page(mupdf_page->ctx, mupdf_page->page, text_device, &ctm, NULL);
   } fz_always (mupdf_document->ctx) {
+    fz_close_device(mupdf_page->ctx, text_device);
     fz_drop_device(mupdf_page->ctx, text_device);
   } fz_catch(mupdf_document->ctx) {
   }
