$NetBSD: patch-plugin.h,v 1.4 2017/12/18 15:07:14 leot Exp $

Updated for MuPDF 1.12.0

Backport from upstream, commit a3f703788f77b19bb986e14666fe0c47911adddc.

--- plugin.h.orig	2017-01-11 21:21:14.000000000 +0000
+++ plugin.h
@@ -3,6 +3,8 @@
 #ifndef PDF_H
 #define PDF_H
 
+#include <stdlib.h>
+#include <string.h>
 #include <stdbool.h>
 #include <zathura/plugin-api.h>
 #include <mupdf/fitz.h>
@@ -21,7 +23,6 @@ typedef struct mupdf_page_s
 {
   fz_page* page; /**< Reference to the mupdf page */
   fz_context* ctx; /**< Context */
-  fz_stext_sheet* sheet; /**< Text sheet */
   fz_stext_page* text; /**< Page text */
   fz_rect bbox; /**< Bbox */
   bool extracted_text; /**< If text has already been extracted */
