$NetBSD: patch-src_calibre_ebooks_pdf_images.cpp,v 1.2 2011/05/21 15:07:48 wiz Exp $

--- src/calibre/ebooks/pdf/images.cpp.orig	2011-04-08 17:20:30.000000000 +0000
+++ src/calibre/ebooks/pdf/images.cpp
@@ -16,6 +16,7 @@
 
 #include "images.h"
 #include "utils.h"
+#include "zlib.h"
 
 #ifdef _WIN32
 inline double round(double x) { return (x-floor(x))>0.5 ? ceil(x) : floor(x); }
