$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_wrapper__gpl.cxx,v 1.1 2018/12/04 12:56:49 ryoon Exp $

--- sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx.orig	2018-10-29 19:55:29.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx
@@ -69,7 +69,7 @@ int main(int argc, char **argv)
 
     // read config file
     globalParams = new GlobalParams();
-    globalParams->setErrQuiet(gTrue);
+    globalParams->setErrQuiet(true);
 #if defined(_MSC_VER)
     globalParams->setupBaseFonts(nullptr);
 #endif
@@ -143,7 +143,7 @@ int main(int argc, char **argv)
                 i,
                 PDFI_OUTDEV_RESOLUTION,
                 PDFI_OUTDEV_RESOLUTION,
-                0, gTrue, gTrue, gTrue);
+                0, true, true, true);
         rDoc.processLinks(&aOutDev, i);
     }
 
