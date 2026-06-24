$NetBSD: patch-CMakeScripts_DefineDependsandFlags.cmake,v 1.6 2026/06/24 21:57:17 wiz Exp $

NetBSD 9 has gcc7 without -lstdc++fs.

--- CMakeScripts/DefineDependsandFlags.cmake.orig	2025-12-13 00:49:28.000000000 +0000
+++ CMakeScripts/DefineDependsandFlags.cmake
@@ -324,8 +324,10 @@ set(CMAKE_ENABLE_EXPORTS ON)
 
 
 
+if (NOT (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD"))
 if (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
     list(APPEND INKSCAPE_LIBS "-lstdc++fs")
+endif()
 endif()
 
 list(APPEND INKSCAPE_INCS_SYS ${Boost_INCLUDE_DIRS})
