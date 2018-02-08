$NetBSD: patch-src_shared_cmake_MacroCheckGccVisibility.cmake,v 1.1 2018/02/08 07:28:58 mrg Exp $

also look for GCC 6, 7, 8 and 9.

--- src/shared/cmake/MacroCheckGccVisibility.cmake.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/shared/cmake/MacroCheckGccVisibility.cmake	2018-02-08 06:10:02.136958010 +0000
@@ -15,7 +15,7 @@
    # get the gcc version
    exec_program(${CMAKE_C_COMPILER} ARGS --version OUTPUT_VARIABLE _gcc_version_info)
 
-   string (REGEX MATCH "[345]\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
+   string (REGEX MATCH "[3456789]\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
    if (NOT _gcc_version)
    
       # clang reports: clang version 1.1 (trunk 95754)
