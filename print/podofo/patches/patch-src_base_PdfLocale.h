$NetBSD: patch-src_base_PdfLocale.h,v 1.1 2013/05/04 12:51:31 joerg Exp $

--- src/base/PdfLocale.h.orig	2013-05-04 02:06:09.000000000 +0000
+++ src/base/PdfLocale.h
@@ -1,7 +1,7 @@
 #ifndef PODOFO_PDFLOCALE_H
 #define PODOFO_PDFLOCALE_H
 
-namespace std { class ios_base; };
+#include <ios>
 
 namespace PoDoFo {
 
