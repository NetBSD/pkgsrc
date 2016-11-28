$NetBSD: patch-search.c,v 1.2 2016/11/28 14:41:40 leot Exp $

Update to mupdf-1.10 API.

--- search.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ search.c
@@ -40,7 +40,7 @@ pdf_page_search_text(zathura_page_t* pag
   }
 
   fz_rect* hit_bbox = fz_malloc_array(mupdf_page->ctx, N_SEARCH_RESULTS, sizeof(fz_rect));
-  int num_results = fz_search_text_page(mupdf_page->ctx, mupdf_page->text,
+  int num_results = fz_search_stext_page(mupdf_page->ctx, mupdf_page->text,
       (char*) text, hit_bbox, N_SEARCH_RESULTS);
 
   for (int i = 0; i < num_results; i++) {
