$NetBSD: patch-filters_krita_png_kis__png__converter.h,v 1.1 2011/02/06 23:59:37 wiz Exp $

Fix build with png-1.5.

--- filters/krita/png/kis_png_converter.h.orig	2007-05-30 21:39:37.000000000 +0000
+++ filters/krita/png/kis_png_converter.h
@@ -21,6 +21,7 @@
 #define _KIS_PNG_CONVERTER_H_
 
 #include <png.h>
+#include <zlib.h>
 
 #include <qvaluevector.h>
 
