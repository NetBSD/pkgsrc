$NetBSD: patch-sources_pdfmodel.cpp,v 1.1 2019/11/08 13:38:48 nia Exp $

Use Arthur as the rendering backend - Splash is currently disabled in pkgsrc.

--- sources/pdfmodel.cpp.orig	2019-07-24 19:18:33.000000000 +0000
+++ sources/pdfmodel.cpp
@@ -301,7 +301,7 @@ const int thinLineMode = 0;
 
 #endif // HAS_POPPLER_24
 
-const int backend = 0;
+const int backend = 1;
 
 } // Defaults
 
