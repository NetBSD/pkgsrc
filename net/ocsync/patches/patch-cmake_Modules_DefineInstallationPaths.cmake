$NetBSD: patch-cmake_Modules_DefineInstallationPaths.cmake,v 1.2 2017/08/19 00:23:36 jlam Exp $

* Fix man pages destination

--- cmake/Modules/DefineInstallationPaths.cmake.orig	2013-10-18 13:11:09.000000000 +0000
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -83,7 +83,7 @@ if (UNIX)
     CACHE PATH "The ${APPLICATION_NAME} sysconfig install dir (default prefix/etc)"
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_MANDIR}"
     CACHE PATH "The ${APPLICATION_NAME} man install dir (default prefix/man)"
   )
   SET(INFO_INSTALL_DIR
