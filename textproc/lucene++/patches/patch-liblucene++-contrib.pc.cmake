$NetBSD: patch-liblucene++-contrib.pc.cmake,v 1.1 2015/10/17 08:12:43 ryoon Exp $

--- liblucene++-contrib.pc.cmake.orig	2015-01-30 16:14:22.000000000 +0000
+++ liblucene++-contrib.pc.cmake
@@ -1,13 +1,13 @@
 prefix=@CMAKE_INSTALL_PREFIX@
 exec_prefix=${prefix}/bin
-libdir=${prefix}/@LIB_DESTINATION@
+libdir=@LIB_DESTINATION@
 includedir=${prefix}/include/lucene++
 lib=lucene++-contrib
 
 Name: liblucene++-contrib
 Description: Contributions for Lucene++ - a C++ search engine, ported from the popular Apache Lucene
 Version: @lucene++_VERSION@
-Libs: -L${prefix}/@LIB_DESTINATION@ -l${lib}
+Libs: -L@LIB_DESTINATION@ -l${lib}
 Cflags: -I${includedir}
 Requires: liblucene++ = @lucene++_VERSION@
 
