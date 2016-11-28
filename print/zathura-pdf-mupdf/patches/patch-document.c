$NetBSD: patch-document.c,v 1.3 2016/11/28 14:41:40 leot Exp $

o Correct the glib-2.0 include header file path.
o Update to mupdf-1.10 API

--- document.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ document.c
@@ -3,10 +3,9 @@
 #define _POSIX_C_SOURCE 1
 
 #include <mupdf/fitz.h>
-#include <mupdf/xps.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 
@@ -109,12 +108,7 @@ pdf_document_save_as(zathura_document_t*
   }
 
   fz_try (mupdf_document->ctx) {
-    /* fz_write_document claims to accepts NULL as third argument but doesn't.
-     * pdf_write_document does not check if the third arguments is NULL for some
-     * options. */
-
-    fz_write_options opts = { 0 }; /* just use the default options */
-    fz_write_document(mupdf_document->ctx, mupdf_document->document, (char*) path, &opts);
+    pdf_save_document(mupdf_document->ctx, pdf_specifics(mupdf_document->ctx, mupdf_document->document), (char*) path, NULL);
   } fz_catch (mupdf_document->ctx) {
     return ZATHURA_ERROR_UNKNOWN;
   }
