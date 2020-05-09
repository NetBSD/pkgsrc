$NetBSD: patch-xylib_util.cpp,v 1.2 2020/05/09 15:19:02 joerg Exp $

* cstdlib needed for strol

--- xylib/util.cpp.orig	2016-12-17 12:45:55.000000000 +0000
+++ xylib/util.cpp
@@ -10,10 +10,11 @@
 #include <limits>
 #include <cassert>
 #include <cerrno>
-#include <boost/detail/endian.hpp>
+#include <cstdlib>
+#include <boost/predef/other/endian.h>
 #include <boost/cstdint.hpp>
 
-#if !defined(BOOST_LITTLE_ENDIAN) && !defined(BOOST_BIG_ENDIAN)
+#if !BOOST_ENDIAN_LITTLE_BYTE && !BOOST_ENDIAN_BIG_BYTE
 #error "Unknown endianness"
 #endif
 
@@ -71,7 +72,7 @@ void my_read(istream &f, char *buf, int 
 
 // change the byte-order from "little endian" to host endian
 // ptr: pointer to the data, size - size in bytes
-#if defined(BOOST_BIG_ENDIAN)
+#if BOOST_ENDIAN_BIG_BYTE
 void le_to_host(void *ptr, int size)
 {
     char *p = (char*) ptr;
