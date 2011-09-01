$NetBSD: patch-Modules_ManageEnvironment.cmake,v 1.1 2011/09/01 11:46:06 obache Exp $

* allow to overwrite PREFIX.

--- Modules/ManageEnvironment.cmake.orig	2011-08-10 06:19:16.000000000 +0000
+++ Modules/ManageEnvironment.cmake
@@ -137,7 +137,9 @@ IF(NOT DEFINED _MANAGE_ENVIRONMENT_CMAKE
     ####################################################################
     # CMake Variables
     #
-    SET(CMAKE_INSTALL_PREFIX "/usr")
+    IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
+	SET(CMAKE_INSTALL_PREFIX "/usr")
+    ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
     SET_COMPILE_ENV(CMAKE_INSTALL_PREFIX "/usr"
 	DISPLAY PATH "Install dir prefix")
     SET_COMPILE_ENV(BIN_DIR  "${CMAKE_INSTALL_PREFIX}/bin"
