$NetBSD: patch-Modules_ManageEnvironment.cmake,v 1.3 2025/08/19 13:31:52 wiz Exp $

* PKGLOCALEDIR support

--- Modules/ManageEnvironment.cmake.orig	2016-01-29 07:15:26.000000000 +0000
+++ Modules/ManageEnvironment.cmake
@@ -71,9 +71,6 @@ FUNCTION(SET_COMPILE_ENV var)
     SET(_force 0)
     SET(_defaultValue "")
     CMAKE_POLICY(PUSH)
-    IF(POLICY CMP0054)
-	CMAKE_POLICY(SET CMP0054 OLD)
-    ENDIF()
 
     FOREACH(_arg ${ARGN})
 	IF("${_arg}" STREQUAL "ENV_NAME")
@@ -148,6 +145,7 @@ M_MSG(${M_INFO1} "CMAKE_SYSTEM_PROCESSOR
 ## Set compile flags
 SET_COMPILE_ENV(BIN_DIR)
 SET_COMPILE_ENV(DATA_DIR)
+SET_COMPILE_ENV(LOCALE_DIR)
 SET_COMPILE_ENV(DOC_DIR)
 SET_COMPILE_ENV(SYSCONF_DIR)
 SET_COMPILE_ENV(LIB_DIR)
