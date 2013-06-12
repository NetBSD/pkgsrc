$NetBSD: patch-modules_ts_src_ts.cpp,v 1.1 2013/06/12 10:13:58 jperkin Exp $

Avoid std::string conflict.

--- modules/ts/src/ts.cpp.orig	2012-07-25 22:55:31.000000000 +0000
+++ modules/ts/src/ts.cpp
@@ -557,7 +557,7 @@ void TS::vprintf( int streams, const cha
     for( int i = 0; i < MAX_IDX; i++ )
         if( (streams & (1 << i)) )
         {
-            output_buf[i] += std::string(str);
+            output_buf[i] += ::std::string(str);
             // in the new GTest-based framework we do not use
             // any output files (except for the automatically generated xml report).
             // if a test fails, all the buffers are printed, so we do not want to duplicate the information and
