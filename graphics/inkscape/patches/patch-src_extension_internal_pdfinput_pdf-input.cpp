$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.cpp,v 1.1 2017/09/09 21:48:56 prlw1 Exp $

Support poppler 0.58
https://gitlab.com/inkscape/inkscape/commit/9418824967eb4c53371ef8588243fed4cab496e0

--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2017-02-13 23:46:57.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -840,14 +840,20 @@ PdfInput::open(::Inkscape::Extension::In
         }
 
         // Parse the document structure
+#if defined(POPPLER_NEW_OBJECT_API)
+        Object obj = page->getContents();
+#else
         Object obj;
         page->getContents(&obj);
+#endif
         if (!obj.isNull()) {
             pdf_parser->parse(&obj);
         }
 
         // Cleanup
+#if !defined(POPPLER_NEW_OBJECT_API)
         obj.free();
+#endif
         delete pdf_parser;
         delete builder;
         g_free(docname);
