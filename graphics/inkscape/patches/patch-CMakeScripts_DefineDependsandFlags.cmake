$NetBSD: patch-CMakeScripts_DefineDependsandFlags.cmake,v 1.5 2023/08/13 14:13:23 ryoon Exp $

NetBSD 9 has gcc7 without -lstdc++fs.

--- CMakeScripts/DefineDependsandFlags.cmake.orig	2023-03-26 17:06:46.000000000 +0000
+++ CMakeScripts/DefineDependsandFlags.cmake
@@ -320,9 +320,11 @@ set(CMAKE_ENABLE_EXPORTS ON)
 
 
 
+if (NOT (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD"))
 if (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
     list(APPEND INKSCAPE_LIBS "-lstdc++fs")
 endif()
+endif()
 
 list(APPEND INKSCAPE_INCS_SYS ${Boost_INCLUDE_DIRS})
 # list(APPEND INKSCAPE_LIBS ${Boost_LIBRARIES})
