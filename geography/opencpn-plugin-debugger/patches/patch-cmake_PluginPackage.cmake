$NetBSD: patch-cmake_PluginPackage.cmake,v 1.1 2025/08/19 12:39:06 wiz Exp $

Fix build with cmake 4.

--- cmake/PluginPackage.cmake.orig	2025-08-19 12:36:29.956649995 +0000
+++ cmake/PluginPackage.cmake
@@ -6,9 +6,6 @@
 
 # build a CPack driven installer package
 #include (InstallRequiredSystemLibraries)
-IF (COMMAND cmake_policy)
-  CMAKE_POLICY(SET CMP0002 OLD)
-ENDIF (COMMAND cmake_policy)
 
 SET(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
 SET(CPACK_PACKAGE_VENDOR "opencpn.org")
