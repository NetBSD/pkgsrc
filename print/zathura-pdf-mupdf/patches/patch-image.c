$NetBSD: patch-image.c,v 1.4 2017/12/18 15:07:14 leot Exp $

Updated for MuPDF 1.12.0

Backport from upstream, commit a3f703788f77b19bb986e14666fe0c47911adddc.

--- image.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ image.c
@@ -43,18 +43,16 @@ pdf_page_images_get(zathura_page_t* page
   /* Extract images */
   mupdf_page_extract_text(mupdf_document, mupdf_page);
 
-  fz_page_block* block;
-  for (block = mupdf_page->text->blocks; block < mupdf_page->text->blocks + mupdf_page->text->len; block++) {
-    if (block->type == FZ_PAGE_BLOCK_IMAGE) {
-      fz_image_block *image_block = block->u.image;
-
+  fz_stext_block* block;
+  for (block = mupdf_page->text->first_block; block; block = block->next) {
+    if (block->type == FZ_STEXT_BLOCK_IMAGE) {
       zathura_image_t* zathura_image = g_malloc(sizeof(zathura_image_t));
 
-      zathura_image->position.x1 = image_block->bbox.x0;
-      zathura_image->position.y1 = image_block->bbox.y0;
-      zathura_image->position.x2 = image_block->bbox.x1;
-      zathura_image->position.y2 = image_block->bbox.y1;
-      zathura_image->data        = image_block->image;
+      zathura_image->position.x1 = block->bbox.x0;
+      zathura_image->position.y1 = block->bbox.y0;
+      zathura_image->position.x2 = block->bbox.x1;
+      zathura_image->position.y2 = block->bbox.y1;
+      zathura_image->data        = block->u.i.image;
 
       girara_list_append(list, zathura_image);
     }
