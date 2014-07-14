$NetBSD: patch-kstars_kstars_fitsviewer.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kstars/kstars/fitsviewer.cpp.orig	2005-09-10 08:17:55.000000000 +0000
+++ kstars/kstars/fitsviewer.cpp
@@ -336,7 +336,7 @@ float * FITSViewer::loadData(const char
     {
     FITS_GETBITPIX32(tempData, pixval_32);
     //pixval_32 = ntohl(pixval_32);
-    if (isnan(pixval_32)) pixval_32 = 0;
+    if (isnan((double)pixval_32)) pixval_32 = 0;
     buffer[i] = pixval_32;
     tempData+=4;
    }
