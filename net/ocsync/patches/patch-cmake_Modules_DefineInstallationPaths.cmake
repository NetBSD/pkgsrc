$NetBSD: patch-cmake_Modules_DefineInstallationPaths.cmake,v 1.1 2013/11/22 12:01:13 ryoon Exp $

* Fix man pages destination

--- cmake/Modules/DefineInstallationPaths.cmake.orig	2013-10-18 13:11:09.000000000 +0000
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -83,7 +83,7 @@ if (UNIX)
     CACHE PATH "The ${APPLICATION_NAME} sysconfig install dir (default prefix/etc)"
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${APPLICATION_NAME} man install dir (default prefix/man)"
   )
   SET(INFO_INSTALL_DIR
