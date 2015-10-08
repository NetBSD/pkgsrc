$NetBSD: patch-modules_ts_src_ts.cpp,v 1.3 2015/10/08 17:45:59 fhajny Exp $

Avoid std::foo conflict.

--- modules/ts/src/ts.cpp.orig	2015-06-03 17:21:34.000000000 +0000
+++ modules/ts/src/ts.cpp
@@ -235,7 +235,7 @@ void BaseTest::safe_run( int start_from
         }
         catch (const TS::FailureCode& fc)
         {
-            std::string errorStr = TS::str_from_code(fc);
+            ::std::string errorStr = TS::str_from_code(fc);
             ts->printf(TS::LOG, "General failure:\n\t%s (%d)\n", errorStr.c_str(), fc);
 
             ts->set_failed_test_info( fc );
@@ -558,7 +558,7 @@ void TS::vprintf( int streams, const cha
     for( int i = 0; i < MAX_IDX; i++ )
         if( (streams & (1 << i)) )
         {
-            output_buf[i] += std::string(str);
+            output_buf[i] += ::std::string(str);
             // in the new GTest-based framework we do not use
             // any output files (except for the automatically generated xml report).
             // if a test fails, all the buffers are printed, so we do not want to duplicate the information and
@@ -613,7 +613,7 @@ void smoothBorder(Mat& img, const Scalar
     Scalar s;
     uchar *p = NULL;
     int n = 100/delta;
-    int nR = std::min(n, (img.rows+1)/2), nC = std::min(n, (img.cols+1)/2);
+    int nR = ::std::min(n, (img.rows+1)/2), nC = ::std::min(n, (img.cols+1)/2);
 
     int r, c, i;
     for(r=0; r<nR; r++)
