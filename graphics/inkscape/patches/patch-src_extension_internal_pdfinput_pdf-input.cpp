$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.cpp,v 1.4 2020/01/11 09:59:05 martin Exp $

Properly use uniqe_ptr method reset() to set the pointer (this is not
compiled as C++14 yet, so no make_unique).

--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2019-01-15 05:29:27.000000000 +0100
+++ src/extension/internal/pdfinput/pdf-input.cpp	2020-01-11 10:36:40.264346717 +0100
@@ -691,10 +691,10 @@
         if (poppler_datadir != NULL) {
             globalParams = new GlobalParams(poppler_datadir);
         } else {
-            globalParams = new GlobalParams();
+            globalParams.reset(new GlobalParams());
         }
 #else
-        globalParams = new GlobalParams();
+        globalParams.reset(new GlobalParams());
 #endif // ENABLE_OSX_APP_LOCATIONS
     }
 
