$NetBSD: patch-kstars_kstars_fitshistogram.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kstars/kstars/fitshistogram.cpp.orig	2006-05-22 18:03:42.000000000 +0000
+++ kstars/kstars/fitshistogram.cpp
@@ -289,7 +289,7 @@ void FITSHistogramCommand::execute()
      
     case FITSImage::FITSLog:
     //coeff = 255. / log(1 + max);
-    coeff = max / log(1 + max);
+    coeff = max / log(1.0 + max);
     
     for (int i=0; i < height; i++)
       for (int j=0; j < width; j++)
@@ -308,7 +308,7 @@ void FITSHistogramCommand::execute()
       
     case FITSImage::FITSSqrt:
     //coeff = 255. / sqrt(max);
-    coeff = max / sqrt(max);
+    coeff = max / sqrt((float)max);
     
     for (int i=0; i < height; i++)
       for (int j=0; j < width; j++)
