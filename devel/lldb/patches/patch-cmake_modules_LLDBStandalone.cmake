$NetBSD: patch-cmake_modules_LLDBStandalone.cmake,v 1.3 2019/06/02 08:35:55 adam Exp $

--- cmake/modules/LLDBStandalone.cmake.orig	2019-01-29 14:23:34.000000000 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -85,7 +85,6 @@ if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURR
   include(AddLLVM)
   include(TableGen)
   include(HandleLLVMOptions)
-  include(CheckAtomic)
 
   if (PYTHON_EXECUTABLE STREQUAL "")
     set(Python_ADDITIONAL_VERSIONS 3.5 3.4 3.3 3.2 3.1 3.0 2.7 2.6 2.5)
