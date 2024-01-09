$NetBSD: patch-CMakeModules_UseCompat.cmake,v 1.1 2024/01/09 15:53:59 chopps Exp $

Expose realpath().

--- CMakeModules/UseCompat.cmake.orig	2023-10-11 07:55:04.000000000 +0000
+++ CMakeModules/UseCompat.cmake
@@ -28,6 +28,8 @@ macro(USE_COMPAT)
     list(APPEND CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)
     list(APPEND CMAKE_REQUIRED_DEFINITIONS -D__BSD_VISIBLE=1)
     list(APPEND CMAKE_REQUIRED_DEFINITIONS -D_DEFAULT_SOURCE)
+    list(APPEND CMAKE_REQUIRED_DEFINITIONS -D_XOPEN_SOURCE)
+    list(APPEND CMAKE_REQUIRED_DEFINITIONS -D_XOPEN_SOURCE_EXTENDED)
     set(CMAKE_REQUIRED_LIBRARIES pthread)
 
     check_symbol_exists(vdprintf "stdio.h;stdarg.h" HAVE_VDPRINTF)
