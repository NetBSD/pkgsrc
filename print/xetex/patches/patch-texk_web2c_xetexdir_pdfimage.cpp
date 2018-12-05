$NetBSD: patch-texk_web2c_xetexdir_pdfimage.cpp,v 1.1 2018/12/05 21:44:03 wiz Exp $

Fix build with poppler-0.71.

--- texk/web2c/xetexdir/pdfimage.cpp.orig	2017-08-06 07:12:02.000000000 +0000
+++ texk/web2c/xetexdir/pdfimage.cpp
@@ -82,19 +82,19 @@ pdf_get_rect(char* filename, int page_nu
 	switch (pdf_box) {
 		default:
 		case pdfbox_crop:
-			r = page->getCropBox();
+			r = (PDFRectangle*)page->getCropBox();
 			break;
 		case pdfbox_media:
-			r = page->getMediaBox();
+			r = (PDFRectangle*)page->getMediaBox();
 			break;
 		case pdfbox_bleed:
-			r = page->getBleedBox();
+			r = (PDFRectangle*)page->getBleedBox();
 			break;
 		case pdfbox_trim:
-			r = page->getTrimBox();
+			r = (PDFRectangle*)page->getTrimBox();
 			break;
 		case pdfbox_art:
-			r = page->getArtBox();
+			r = (PDFRectangle*)page->getArtBox();
 			break;
 	}
 
