$NetBSD: patch-cmake_modules_LLDBStandalone.cmake,v 1.2 2016/11/14 20:15:33 ryoon Exp $

--- cmake/modules/LLDBStandalone.cmake.orig	2016-07-15 22:46:15.000000000 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -86,7 +86,6 @@ if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURR
 
   include(AddLLVM)
   include(HandleLLVMOptions)
-  include(CheckAtomic)
 
   if (PYTHON_EXECUTABLE STREQUAL "")
     set(Python_ADDITIONAL_VERSIONS 3.5 3.4 3.3 3.2 3.1 3.0 2.7 2.6 2.5)
