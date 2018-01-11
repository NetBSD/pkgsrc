$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_pdfioutdev__gpl.cxx,v 1.1 2018/01/11 12:52:05 ryoon Exp $

* Fix build with poppler-0.62.0

--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2017-12-12 17:45:07.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -36,7 +36,7 @@
 // FIXME: we can't use #if POPPLER_CHECK_VERSION(0, 21, 0) && !POPPLER_CHECK_VERSION(0, 21, 1)
 //        because the internal poppler does not provide poppler-version.h and the macro always returns 0
 #if POPPLER_CHECK_VERSION(0, 21, 1)
-#include "UTF8.h"
+#include "UnicodeMapFuncs.h"
 #elif POPPLER_CHECK_VERSION(0, 21, 0)
 #include "UTF.h"
 #else
@@ -918,7 +918,7 @@ void PDFOutDev::drawChar(GfxState *state
             );
 
     // silence spurious warning
-    (void)&mapUCS2;
+    (void)&mapUTF16;
 
     char buf[9];
     for( int i=0; i<uLen; ++i )
