$NetBSD: patch-select.c,v 1.1 2017/12/18 15:07:14 leot Exp $

Updated for MuPDF 1.12.0

Backport from upstream, commit a3f703788f77b19bb986e14666fe0c47911adddc.

--- select.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ select.c
@@ -24,9 +24,14 @@ pdf_page_get_text(zathura_page_t* page, 
     mupdf_page_extract_text(mupdf_document, mupdf_page);
   }
 
-  fz_rect rect = { rectangle.x1, rectangle.y1, rectangle.x2, rectangle.y2 };
+  fz_point a = { rectangle.x1, rectangle.y1 };
+  fz_point b = { rectangle.x2, rectangle.y2 };
 
-  return fz_copy_selection(mupdf_page->ctx, mupdf_page->text, rect);
+#ifdef _WIN32
+  return fz_copy_selection(mupdf_page->ctx, mupdf_page->text, a, b, 1);
+#else
+  return fz_copy_selection(mupdf_page->ctx, mupdf_page->text, a, b, 0);
+#endif
 
 error_ret:
 
