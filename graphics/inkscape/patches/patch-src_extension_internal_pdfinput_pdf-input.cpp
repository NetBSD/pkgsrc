$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.cpp,v 1.8 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2026-04-23 22:59:59.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -808,7 +808,11 @@ PdfInput::add_builder_page(std::shared_ptr<PDFDoc>pdf_
     }
 
     // Apply crop settings
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+    std::optional<PDFRectangle> clipToBox;
+#else
     _POPPLER_CONST PDFRectangle *clipToBox = nullptr;
+#endif
 
     if (crop_to == "media-box") {
         clipToBox = page->getMediaBox();
@@ -822,8 +826,16 @@ PdfInput::add_builder_page(std::shared_ptr<PDFDoc>pdf_
         clipToBox = page->getArtBox();
     }
 
+    std::optional<PDFRectangle> cropBox;
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+    cropBox = clipToBox;
+#else
+    if (clipToBox) {
+        cropBox = *clipToBox;
+    }
+#endif
     // Create parser  (extension/internal/pdfinput/pdf-parser.h)
-    auto pdf_parser = PdfParser(pdf_doc, builder, page, clipToBox);
+    auto pdf_parser = PdfParser(pdf_doc, builder, page, cropBox);
 
     // Set up approximation precision for parser. Used for converting Mesh Gradients into tiles.
     if ( color_delta <= 0.0 ) {
