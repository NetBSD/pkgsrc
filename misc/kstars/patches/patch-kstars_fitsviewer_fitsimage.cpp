$NetBSD: patch-kstars_fitsviewer_fitsimage.cpp,v 1.1 2013/06/23 19:09:15 jperkin Exp $

Avoid "ambiguous call to overloaded function" errors.

--- kstars/fitsviewer/fitsimage.cpp.orig	2013-05-03 04:38:11.831303171 +0000
+++ kstars/fitsviewer/fitsimage.cpp
@@ -474,7 +474,7 @@ bool FITSImage::checkCollision(Edge* s1,
     int diff_x=s1->x - s2->x;
     int diff_y=s1->y - s2->y;
 
-    dis = abs( sqrt( diff_x*diff_x + diff_y*diff_y));
+    dis = abs( sqrt((float)diff_x*diff_x + diff_y*diff_y));
     dis -= s1->width/2;
     dis -= s2->width/2;
 
@@ -857,7 +857,7 @@ void FITSImage::applyFilter(FITSScale ty
         break;
 
     case FITS_LOG:
-        coeff = max / log(1 + max);
+        coeff = max / log((float)1 + max);
 
         for (int i=0; i < height; i++)
             for (int j=0; j < width; j++)
@@ -873,7 +873,7 @@ void FITSImage::applyFilter(FITSScale ty
         break;
 
     case FITS_SQRT:
-        coeff = max / sqrt(max);
+        coeff = max / sqrt((float)max);
 
         for (int i=0; i < height; i++)
             for (int j=0; j < width; j++)
