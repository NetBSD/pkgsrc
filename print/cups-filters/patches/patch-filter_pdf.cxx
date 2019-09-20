$NetBSD: patch-filter_pdf.cxx,v 1.3 2019/09/20 11:11:52 prlw1 Exp $

Fix build with qpdf 9.0
https://github.com/OpenPrinting/cups-filters/commit/1878ecd2ef533c3dbe6e6bc29018ce4bf8246e83

--- filter/pdf.cxx.orig	2019-05-16 13:02:29.000000000 +0000
+++ filter/pdf.cxx
@@ -20,6 +20,7 @@
 #include "pdf.h"
 #include <vector>
 #include <string>
+#include <cstring>
 #include <qpdf/QPDF.hh>
 #include <qpdf/QPDFObjectHandle.hh>
 #include <qpdf/QPDFWriter.hh>
