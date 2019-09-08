$NetBSD: patch-src_libcec_cmake_SetBuildInfo.cmake,v 1.1 2019/09/08 12:30:54 nia Exp $

Don't use non-standard hostname args.

--- src/libcec/cmake/SetBuildInfo.cmake.orig	2018-12-21 21:34:45.000000000 +0000
+++ src/libcec/cmake/SetBuildInfo.cmake
@@ -45,8 +45,6 @@ else()
   # add host on which this was built to compile info
   find_program(HAVE_HOSTNAME_BIN hostname /bin /usr/bin /usr/local/bin)
   if(HAVE_HOSTNAME_BIN)
-    exec_program(hostname ARGS -f OUTPUT_VARIABLE BUILD_HOST)
-    set(LIB_INFO "${LIB_INFO}@${BUILD_HOST}")
   endif()
 
   # add host info on which this was built to compile info
