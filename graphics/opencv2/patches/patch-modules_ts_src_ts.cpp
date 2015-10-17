$NetBSD: patch-modules_ts_src_ts.cpp,v 1.1 2015/10/17 10:28:43 fhajny Exp $

Avoid std::foo conflict.

--- modules/ts/src/ts.cpp.orig	2013-04-05 09:00:20.000000000 +0000
+++ modules/ts/src/ts.cpp
@@ -562,7 +562,7 @@ void TS::vprintf( int streams, const cha
     for( int i = 0; i < MAX_IDX; i++ )
         if( (streams & (1 << i)) )
         {
-            output_buf[i] += std::string(str);
+            output_buf[i] += ::std::string(str);
             // in the new GTest-based framework we do not use
             // any output files (except for the automatically generated xml report).
             // if a test fails, all the buffers are printed, so we do not want to duplicate the information and
@@ -617,7 +617,7 @@ void smoothBorder(Mat& img, const Scalar
     Scalar s;
     uchar *p = NULL;
     int n = 100/delta;
-    int nR = std::min(n, (img.rows+1)/2), nC = std::min(n, (img.cols+1)/2);
+    int nR = ::std::min(n, (img.rows+1)/2), nC = ::std::min(n, (img.cols+1)/2);
 
     int r, c, i;
     for(r=0; r<nR; r++)
