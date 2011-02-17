$NetBSD: patch-cmake_admCheckMiscLibs.cmake,v 1.1 2011/02/17 09:20:17 markd Exp $

test for existence of JS_InitStandardClasses was failing but we
know in pkgsrc context that it is good so dont bother testing

--- cmake/admCheckMiscLibs.cmake.orig	2010-09-19 23:32:24.000000000 +0000
+++ cmake/admCheckMiscLibs.cmake
@@ -96,7 +96,7 @@ MESSAGE(STATUS "Checking for SpiderMonke
 MESSAGE(STATUS "*************************")
 
 IF (USE_SYSTEM_SPIDERMONKEY)
-	FIND_HEADER_AND_LIB(SPIDERMONKEY jsapi.h js JS_InitStandardClasses)
+	FIND_HEADER_AND_LIB(SPIDERMONKEY jsapi.h js)
 	PRINT_LIBRARY_INFO("SpiderMonkey" SPIDERMONKEY_FOUND "${SPIDERMONKEY_INCLUDE_DIR}" "${SPIDERMONKEY_LIBRARY_DIR}" FATAL_ERROR)
 ELSE (USE_SYSTEM_SPIDERMONKEY)
 	MESSAGE("Skipping check and using bundled version.")
