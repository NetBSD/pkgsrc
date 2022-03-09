$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.cpp,v 1.6 2022/03/09 09:10:17 wiz Exp $

Fix build with poppler 22.03.
https://gitlab.com/inkscape/inkscape/-/merge_requests/4116/diffs?commit_id=15ab83e02b07018c3ffd4952a2623393187659e0

--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2022-02-05 01:21:47.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -666,10 +666,13 @@ PdfInput::open(::Inkscape::Extension::In
     // PDFDoc is from poppler. PDFDoc is used for preview and for native import.
     std::shared_ptr<PDFDoc> pdf_doc;
 
-    // poppler does not use glib g_open. So on win32 we must use unicode call. code was copied from
-    // glib gstdio.c
+
+#if POPPLER_CHECK_VERSION(22, 3, 0)
+    pdf_doc = std::make_shared<PDFDoc>(std::make_unique<GooString>(uri)); // TODO: Could ask for password
+#else
     GooString *filename_goo = new GooString(uri);
-    pdf_doc = std::make_shared<PDFDoc>(filename_goo, nullptr, nullptr, nullptr);   // TODO: Could ask for password
+    pdf_doc = std::make_shared<PDFDoc>(filename_goo, nullptr, nullptr, nullptr); // TODO: Could ask for password
+#endif
 
     if (!pdf_doc->isOk()) {
         int error = pdf_doc->getErrorCode();
