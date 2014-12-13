$NetBSD: patch-Modules_ManageEnvironmentCommon.cmake,v 1.1 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageEnvironmentCommon.cmake.orig	2014-10-28 05:05:31.000000000 +0000
+++ Modules/ManageEnvironmentCommon.cmake
@@ -41,6 +41,7 @@ SET(CMAKE_INSTALL_PREFIX "/usr" CACHE PA
 SET(BIN_DIR     "${CMAKE_INSTALL_PREFIX}/bin"     CACHE PATH "Binary dir")
 SET(DATA_DIR    "${CMAKE_INSTALL_PREFIX}/share"   CACHE PATH "Data dir")
 SET(DOC_DIR     "${DATA_DIR}/doc"                 CACHE PATH "Doc dir")
+SET(LOCALE_DIR  "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LOCALEDIR}" CACHE PATH "Locale dir")
 SET(LIBEXEC_DIR "${CMAKE_INSTALL_PREFIX}/libexec" CACHE PATH "Libexec dir")
 SET(SYSCONF_DIR "/etc"                            CACHE PATH 
     "System configuration dir"
