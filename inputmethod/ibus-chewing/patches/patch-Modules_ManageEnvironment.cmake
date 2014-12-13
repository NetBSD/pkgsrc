$NetBSD: patch-Modules_ManageEnvironment.cmake,v 1.2 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageEnvironment.cmake.orig	2014-10-28 05:05:31.000000000 +0000
+++ Modules/ManageEnvironment.cmake
@@ -144,6 +144,7 @@ M_MSG(${M_INFO1} "CMAKE_SYSTEM_PROCESSOR
 ## Set compile flags
 SET_COMPILE_ENV(BIN_DIR)
 SET_COMPILE_ENV(DATA_DIR)
+SET_COMPILE_ENV(LOCALE_DIR)
 SET_COMPILE_ENV(DOC_DIR)
 SET_COMPILE_ENV(SYSCONF_DIR)
 SET_COMPILE_ENV(LIB_DIR)
