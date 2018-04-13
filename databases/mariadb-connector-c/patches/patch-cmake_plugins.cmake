$NetBSD: patch-cmake_plugins.cmake,v 1.1 2018/04/13 08:04:14 fhajny Exp $

Make sure curl support can be turned off.

--- cmake/plugins.cmake.orig	2018-01-17 11:43:58.000000000 +0000
+++ cmake/plugins.cmake
@@ -96,7 +96,7 @@ ENDFOREACH()
 MESSAGE1(plugin_config "Plugin configuration:${plugin_config}")
 MESSAGE1(LIBMARIADB_SOURCES "STATIC PLUGIN SOURCES: ${LIBMARIADB_SOURCES}")
 
-IF(NOT REMOTEIO_PLUGIN_TYPE MATCHES "NO")
+IF(WITH_CURL AND NOT REMOTEIO_PLUGIN_TYPE MATCHES "NO")
   FIND_PACKAGE(CURL)
 ENDIF()
 
