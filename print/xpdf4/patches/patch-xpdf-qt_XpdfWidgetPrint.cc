$NetBSD: patch-xpdf-qt_XpdfWidgetPrint.cc,v 1.1 2019/10/22 22:21:26 nia Exp $

Use CUPS on !Linux.

--- xpdf-qt/XpdfWidgetPrint.cc.orig	2019-09-25 19:54:33.000000000 +0000
+++ xpdf-qt/XpdfWidgetPrint.cc
@@ -21,7 +21,7 @@
 #elif defined(__APPLE__)
 #  include <CoreFoundation/CoreFoundation.h>
 #  include <ApplicationServices/ApplicationServices.h>
-#elif defined(__linux__)
+#else
 #  include "PSOutputDev.h"
 #  include <cups/cups.h>
 #endif
@@ -315,7 +315,7 @@ XpdfWidget::ErrorCode printPDF(PDFDoc *d
 // Linux
 //------------------------------------------------------------------------
 
-#elif defined(__linux__)
+#else
 
 static void fileOut(void *stream, const char *data, int len) {
   fwrite(data, 1, len, (FILE *)stream);
