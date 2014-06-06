$NetBSD: patch-cmake_Modules_FindJSONC.cmake,v 1.1.1.1 2014/06/06 14:57:00 abs Exp $

Update for json-c 0.11 and later

--- cmake/Modules/FindJSONC.cmake.orig	2013-05-02 16:40:04.000000000 +0000
+++ cmake/Modules/FindJSONC.cmake
@@ -6,8 +6,8 @@
 #  JSONC_INCLUDE_DIR - The JSON-C include directory.
 #  JSONC_LIBRARY     - The JSON-C library to link against.
 
-FIND_PATH(JSONC_INCLUDE_DIR json/json.h)
-FIND_LIBRARY(JSONC_LIBRARY NAMES json)
+FIND_PATH(JSONC_INCLUDE_DIR NAMES json-c/json.h json/json.h)
+FIND_LIBRARY(JSONC_LIBRARY NAMES json-c json)
 
 IF (JSONC_INCLUDE_DIR AND JSONC_LIBRARY)
    SET(JSONC_FOUND TRUE)
