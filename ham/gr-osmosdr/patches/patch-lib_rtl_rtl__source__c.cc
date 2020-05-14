$NetBSD: patch-lib_rtl_rtl__source__c.cc,v 1.1 2020/05/14 19:21:34 joerg Exp $

--- lib/rtl/rtl_source_c.cc.orig	2020-05-10 20:52:02.745101595 +0000
+++ lib/rtl/rtl_source_c.cc
@@ -32,7 +32,7 @@
 
 #include <boost/assign.hpp>
 #include <boost/format.hpp>
-#include <boost/detail/endian.hpp>
+#include <boost/predef/other/endian.h>
 #include <boost/algorithm/string.hpp>
 
 #include <stdexcept>
@@ -173,10 +173,10 @@ rtl_source_c::rtl_source_c (const std::s
 
   // create a lookup table for gr_complex values
   for (unsigned int i = 0; i <= 0xffff; i++) {
-#ifdef BOOST_LITTLE_ENDIAN
+#if BOOST_ENDIAN_LITTLE_BYTE
     _lut.push_back( gr_complex( (float(i & 0xff) - 127.4f) * (1.0f/128.0f),
                                 (float(i >> 8) - 127.4f) * (1.0f/128.0f) ) );
-#else // BOOST_BIG_ENDIAN
+#else // BOOST_ENDIAN_BIG_BYTE
     _lut.push_back( gr_complex( (float(i >> 8) - 127.4f) * (1.0f/128.0f),
                                 (float(i & 0xff) - 127.4f) * (1.0f/128.0f) ) );
 #endif
