$NetBSD: patch-zathura-pdf-mupdf_search.c,v 1.1 2019/08/03 14:48:48 leot Exp $

Backport upstream commit 95c830c9 to fix the build with MuPDF 1.16.0:

 <https://git.pwmt.org/pwmt/zathura-pdf-mupdf/commit/95c830c9f6cfe4ba99535ecfba0a700ceb15a25a>

--- zathura-pdf-mupdf/search.c.orig	2018-10-04 17:33:46.000000000 +0000
+++ zathura-pdf-mupdf/search.c
@@ -39,7 +39,7 @@ pdf_page_search_text(zathura_page_t* pag
     mupdf_page_extract_text(mupdf_document, mupdf_page);
   }
 
-  fz_quad* hit_bbox = fz_malloc_array(mupdf_page->ctx, N_SEARCH_RESULTS, sizeof(fz_quad));
+  fz_quad* hit_bbox = fz_malloc_array(mupdf_page->ctx, N_SEARCH_RESULTS, fz_quad);
   int num_results = fz_search_stext_page(mupdf_page->ctx, mupdf_page->text,
       text, hit_bbox, N_SEARCH_RESULTS);
 
