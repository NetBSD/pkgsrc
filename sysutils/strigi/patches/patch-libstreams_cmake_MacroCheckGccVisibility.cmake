$NetBSD: patch-libstreams_cmake_MacroCheckGccVisibility.cmake,v 1.1 2018/02/08 07:28:58 mrg Exp $

support netbsd 6, 7, 8, and 9.

--- libstreams/cmake/MacroCheckGccVisibility.cmake.orig	2013-02-05 13:34:57.000000000 -0800
+++ libstreams/cmake/MacroCheckGccVisibility.cmake	2018-02-07 22:38:19.000000000 -0800
@@ -15,7 +15,7 @@
    # get the gcc version
    exec_program(${CMAKE_C_COMPILER} ARGS ${CMAKE_C_COMPILER_ARG1} --version OUTPUT_VARIABLE _gcc_version_info)
 
-   string (REGEX MATCH "[345]\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
+   string (REGEX MATCH "[3456789]\\.[0-9]\\.[0-9]" _gcc_version "${_gcc_version_info}")
    # gcc on mac just reports: "gcc (GCC) 3.3 20030304 ..." without the patch level, handle this here:
    if (NOT _gcc_version)
       string (REGEX REPLACE ".*\\(GCC\\).* ([34]\\.[0-9]) .*" "\\1.0" _gcc_version "${_gcc_version_info}")
