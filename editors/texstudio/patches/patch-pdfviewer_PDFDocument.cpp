$NetBSD: patch-pdfviewer_PDFDocument.cpp,v 1.2 2019/01/21 10:12:13 markd Exp $

Avoid ambiguous function call.

--- src/pdfviewer/PDFDocument.cpp.orig	2017-08-12 12:00:03.000000000 +0000
+++ src/pdfviewer/PDFDocument.cpp
@@ -3095,7 +3095,7 @@ retryNow:
 			pdfWidget->setFocus();
 
 		// set page viewer only once
-                int maxDigits = 1 + qFloor(log10(pdfWidget->realNumPages()));
+                int maxDigits = 1 + qFloor(log10((float)pdfWidget->realNumPages()));
 		//if (maxDigits < 2) maxDigits = 2;
 		leCurrentPage->setMaxLength(maxDigits);
 		leCurrentPage->setFixedWidth(fontMetrics().width(QString(maxDigits + 1, '#')));
