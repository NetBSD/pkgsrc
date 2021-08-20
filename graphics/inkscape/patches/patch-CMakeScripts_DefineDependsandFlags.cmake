$NetBSD: patch-CMakeScripts_DefineDependsandFlags.cmake,v 1.4 2021/08/20 11:40:15 nia Exp $

NetBSD 9 has gcc7 without -lstdc++fs.

--- CMakeScripts/DefineDependsandFlags.cmake.orig	2021-05-17 19:26:40.000000000 +0000
+++ CMakeScripts/DefineDependsandFlags.cmake
@@ -298,9 +298,11 @@ endif()
 
 find_package(Boost 1.19.0 REQUIRED COMPONENTS filesystem)
 
+if (NOT (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD"))
 if (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
     list(APPEND INKSCAPE_LIBS "-lstdc++fs")
 endif()
+endif()
 
 list(APPEND INKSCAPE_INCS_SYS ${Boost_INCLUDE_DIRS})
 # list(APPEND INKSCAPE_LIBS ${Boost_LIBRARIES})
