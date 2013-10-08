$NetBSD: patch-Modules_ManageEnvironment.cmake,v 1.1 2013/10/08 12:06:23 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageEnvironment.cmake.orig	2012-11-26 07:37:40.000000000 +0000
+++ Modules/ManageEnvironment.cmake
@@ -163,6 +163,8 @@ IF(NOT DEFINED _MANAGE_ENVIRONMENT_CMAKE
 	CACHE PATH "Data dir")
     SET_COMPILE_ENV(DOC_DIR  "${DATA_DIR}/doc"
 	CACHE PATH "Documentation dir")
+    SET_COMPILE_ENV(LOCALE_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LOCALEDIR}"
+	CACHE PATH "Locale dir")
     SET_COMPILE_ENV(SYSCONF_DIR "/etc"
 	CACHE PATH "System configuration dir")
     SET_COMPILE_ENV(LIBEXEC_DIR "${CMAKE_INSTALL_PREFIX}/libexec"
