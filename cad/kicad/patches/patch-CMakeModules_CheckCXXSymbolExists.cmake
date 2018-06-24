$NetBSD: patch-CMakeModules_CheckCXXSymbolExists.cmake,v 1.1 2018/06/24 13:02:00 mef Exp $

Upgrading cmake 3.10 to 3.11 lost the definition of _CHECK_SYMBOL_EXISTS, this makes 
build fails. Following work around of one line patch is provided by @tristelo.
Also see 
https://lists.launchpad.net/kicad-developers/msg35240.html

--- CMakeModules/CheckCXXSymbolExists.cmake.orig	2018-04-14 07:05:29.298280606 +0000
+++ CMakeModules/CheckCXXSymbolExists.cmake
@@ -38,5 +38,5 @@
 include(CheckSymbolExists)
 
 macro(CHECK_CXX_SYMBOL_EXISTS SYMBOL FILES VARIABLE)
-  _CHECK_SYMBOL_EXISTS("${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.cxx" "${SYMBOL}" "${FILES}" "${VARIABLE}" )
+  CHECK_SYMBOL_EXISTS("${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.cxx" "${SYMBOL}" "${FILES}" "${VARIABLE}" )
 endmacro()
