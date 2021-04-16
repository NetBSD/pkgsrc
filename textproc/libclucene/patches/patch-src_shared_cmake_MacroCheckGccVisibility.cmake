$NetBSD: patch-src_shared_cmake_MacroCheckGccVisibility.cmake,v 1.2 2021/04/16 14:55:42 ryoon Exp $

* Match all GCC versions, ignore GCC 2 or earlier cases.
  Fix build with GCC 10 or later.

--- src/shared/cmake/MacroCheckGccVisibility.cmake.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/shared/cmake/MacroCheckGccVisibility.cmake	2018-02-08 06:10:02.136958010 +0000
@@ -15,7 +15,7 @@
    # get the gcc version
    exec_program(${CMAKE_C_COMPILER} ARGS --version OUTPUT_VARIABLE _gcc_version_info)
 
-   string (REGEX MATCH "[345]\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
+   string (REGEX MATCH "[0-9]+\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
    if (NOT _gcc_version)
    
       # clang reports: clang version 1.1 (trunk 95754)
