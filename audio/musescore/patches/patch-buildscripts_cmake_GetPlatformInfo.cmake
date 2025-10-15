$NetBSD: patch-buildscripts_cmake_GetPlatformInfo.cmake,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Add an OS define for NetBSD.

--- buildscripts/cmake/GetPlatformInfo.cmake.orig	2025-04-24 13:59:18.000000000 +0000
+++ buildscripts/cmake/GetPlatformInfo.cmake
@@ -30,6 +30,8 @@ elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES
     set(OS_IS_LIN 1)
 elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "FreeBSD")
     set(OS_IS_FBSD 1)
+elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "NetBSD")
+    set(OS_IS_NBSD 1)
 elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin")
     set(OS_IS_MAC 1)
 else()
