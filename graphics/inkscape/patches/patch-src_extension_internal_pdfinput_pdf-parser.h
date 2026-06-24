$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.10 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2026-04-23 22:59:59.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -112,8 +112,8 @@ class PdfParser { (public)
 class PdfParser {
 public:
 
-  // Constructor for regular output.
-    PdfParser(std::shared_ptr<PDFDoc> pdf_doc, SvgBuilder *builderA, Page *page, _POPPLER_CONST PDFRectangle *cropBox);
+    // Constructor for regular output.
+    PdfParser(std::shared_ptr<PDFDoc> pdf_doc, SvgBuilder *builderA, Page *page, const std::optional<PDFRectangle> &cropBox);
     // Constructor for a sub-page object.
     PdfParser(XRef *xrefA, SvgBuilder *builderA, Dict *resDict, _POPPLER_CONST PDFRectangle *box);
 
