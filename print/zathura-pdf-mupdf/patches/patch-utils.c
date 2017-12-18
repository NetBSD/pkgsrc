$NetBSD: patch-utils.c,v 1.4 2017/12/18 15:07:14 leot Exp $

Updated for MuPDF 1.12.0

Backport from upstream, commit a3f703788f77b19bb986e14666fe0c47911adddc.

--- utils.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ utils.c
@@ -7,17 +7,17 @@
 void
 mupdf_page_extract_text(mupdf_document_t* mupdf_document, mupdf_page_t* mupdf_page) {
   if (mupdf_document == NULL || mupdf_document->ctx == NULL || mupdf_page == NULL ||
-      mupdf_page->sheet == NULL || mupdf_page->text == NULL) {
+      mupdf_page->text == NULL) {
     return;
   }
 
   fz_device* text_device = NULL;
 
   fz_try (mupdf_page->ctx) {
-    text_device = fz_new_stext_device(mupdf_page->ctx, mupdf_page->sheet, mupdf_page->text, NULL);
+    text_device = fz_new_stext_device(mupdf_page->ctx, mupdf_page->text, NULL);
 
-    /* Disable FZ_IGNORE_IMAGE to collect image blocks */
-    fz_disable_device_hints(mupdf_page->ctx, text_device, FZ_IGNORE_IMAGE);
+    /* Disable FZ_DONT_INTERPOLATE_IMAGES to collect image blocks */
+    fz_disable_device_hints(mupdf_page->ctx, text_device, FZ_DONT_INTERPOLATE_IMAGES);
 
     fz_matrix ctm;
     fz_scale(&ctm, 1.0, 1.0);
