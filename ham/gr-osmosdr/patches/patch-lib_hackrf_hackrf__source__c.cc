$NetBSD: patch-lib_hackrf_hackrf__source__c.cc,v 1.1 2020/05/14 19:21:34 joerg Exp $

--- lib/hackrf/hackrf_source_c.cc.orig	2020-05-10 20:52:00.651452193 +0000
+++ lib/hackrf/hackrf_source_c.cc
@@ -32,7 +32,7 @@
 
 #include <boost/assign.hpp>
 #include <boost/format.hpp>
-#include <boost/detail/endian.hpp>
+#include <boost/predef/other/endian.h>
 #include <boost/algorithm/string.hpp>
 #include <boost/thread/thread.hpp>
 
@@ -119,10 +119,10 @@ hackrf_source_c::hackrf_source_c (const 
 
   // create a lookup table for gr_complex values
   for (unsigned int i = 0; i <= 0xffff; i++) {
-#ifdef BOOST_LITTLE_ENDIAN
+#if BOOST_ENDIAN_BIG_BYTE
     _lut.push_back( gr_complex( (float(char(i & 0xff))) * (1.0f/128.0f),
                                 (float(char(i >> 8))) * (1.0f/128.0f) ) );
-#else // BOOST_BIG_ENDIAN
+#else // BOOST_ENDIAN_BIG_BYTE
     _lut.push_back( gr_complex( (float(char(i >> 8))) * (1.0f/128.0f),
                                 (float(char(i & 0xff))) * (1.0f/128.0f) ) );
 #endif
