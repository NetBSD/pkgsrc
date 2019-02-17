$NetBSD: patch-texk_web2c_luatexdir_image_pdftoepdf.w,v 1.8 2019/02/17 11:17:37 tnn Exp $

--- texk/web2c/luatexdir/image/pdftoepdf.w.orig	2018-01-17 18:00:12.000000000 +0000
+++ texk/web2c/luatexdir/image/pdftoepdf.w
@@ -33,9 +33,9 @@
 
 */
 
-extern void md5(Guchar *msg, int msgLen, Guchar *digest);
+extern void md5(unsigned char *msg, int msgLen, unsigned char *digest);
 
-static GBool isInit = gFalse;
+static bool isInit = false;
 
 /* Maintain AVL tree of all PDF files for embedding */
 
@@ -361,12 +361,12 @@ void copyReal(PDF pdf, double d)
     pdf->cave = true;
 }
 
-static void copyString(PDF pdf, GooString * string)
+static void copyString(PDF pdf, const GooString * string)
 {
-    char *p;
+    const char *p;
     unsigned char c;
     size_t i, l;
-    p = string->getCString();
+    p = string->c_str();
     l = (size_t) string->getLength();
     if (pdf->cave)
         pdf_out(pdf, ' ');
@@ -393,7 +393,7 @@ static void copyString(PDF pdf, GooStrin
     pdf->cave = true;
 }
 
-static void copyName(PDF pdf, char *s)
+static void copyName(PDF pdf, const char *s)
 {
     pdf_out(pdf, '/');
     for (; *s != 0; s++) {
@@ -468,7 +468,7 @@ static void copyObject(PDF pdf, PdfDocum
         break;
     /*
     case objNum:
-        GBool isNum() { return type == objInt || type == objReal; }
+        bool isNum() { return type == objInt || type == objReal; }
         break;
     */
     case objString:
@@ -529,26 +529,30 @@ static void writeRefs(PDF pdf, PdfDocume
 
 static PDFRectangle *get_pagebox(Page * page, int pagebox_spec)
 {
+    const PDFRectangle *ret;
+
     switch (pagebox_spec) {
         case PDF_BOX_SPEC_MEDIA:
-            return page->getMediaBox();
+            ret = page->getMediaBox();
             break;
         case PDF_BOX_SPEC_CROP:
-            return page->getCropBox();
+            ret = page->getCropBox();
             break;
         case PDF_BOX_SPEC_BLEED:
-            return page->getBleedBox();
+            ret = page->getBleedBox();
             break;
         case PDF_BOX_SPEC_TRIM:
-            return page->getTrimBox();
+            ret = page->getTrimBox();
             break;
         case PDF_BOX_SPEC_ART:
-            return page->getArtBox();
+            ret = page->getArtBox();
             break;
         default:
-            return page->getMediaBox();
+            ret = page->getMediaBox();
             break;
     }
+
+    return const_cast<PDFRectangle *>(ret);
 }
 
 /*
@@ -587,11 +591,11 @@ void read_pdf_info(image_dict * idict)
     PDFRectangle *pagebox;
     int pdf_major_version_found, pdf_minor_version_found;
     float xsize, ysize, xorig, yorig;
-    if (isInit == gFalse) {
+    if (isInit == false) {
         if (!(globalParams))
             globalParams = new GlobalParams();
-        globalParams->setErrQuiet(gFalse);
-        isInit = gTrue;
+        globalParams->setErrQuiet(false);
+        isInit = true;
     }
     if (img_type(idict) == IMG_TYPE_PDF)
         pdf_doc = refPdfDocument(img_filepath(idict), FE_FAIL);
@@ -966,7 +970,7 @@ void epdf_free()
     if (PdfDocumentTree != NULL)
         avl_destroy(PdfDocumentTree, destroyPdfDocument);
     PdfDocumentTree = NULL;
-    if (isInit == gTrue)
+    if (isInit == true)
         delete globalParams;
-    isInit = gFalse;
+    isInit = false;
 }
