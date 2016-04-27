$NetBSD: patch-document.c,v 1.2 2016/04/27 12:38:45 leot Exp $

o Correct the glib-2.0 include header file path.
o Update to mupdf-1.9 API

--- document.c.orig	2016-02-14 22:49:46.000000000 +0000
+++ document.c
@@ -6,7 +6,7 @@
 #include <mupdf/xps.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 
@@ -109,12 +109,7 @@ pdf_document_save_as(zathura_document_t*
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
