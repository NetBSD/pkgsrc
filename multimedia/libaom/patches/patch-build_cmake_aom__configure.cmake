$NetBSD: patch-build_cmake_aom__configure.cmake,v 1.1 2018/09/30 18:58:16 maya Exp $

Don't disable fortify just because it's a release build.

--- build/cmake/aom_configure.cmake.orig	2018-09-28 20:57:38.000000000 +0000
+++ build/cmake/aom_configure.cmake
@@ -290,9 +290,6 @@ else()
     add_compiler_flag_if_supported("-Werror")
   endif()
 
-  if("${CMAKE_BUILD_TYPE}" MATCHES "Rel")
-    add_compiler_flag_if_supported("-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0")
-  endif()
   add_compiler_flag_if_supported("-D_LARGEFILE_SOURCE")
   add_compiler_flag_if_supported("-D_FILE_OFFSET_BITS=64")
 endif()
