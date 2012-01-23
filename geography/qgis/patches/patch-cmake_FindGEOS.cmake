$NetBSD: patch-cmake_FindGEOS.cmake,v 1.1 2012/01/23 08:58:00 adam Exp $

Avoid application bundles.

--- cmake/FindGEOS.cmake.orig	2011-06-07 06:45:26.000000000 +0000
+++ cmake/FindGEOS.cmake
@@ -45,7 +45,7 @@ ELSE(WIN32)
 
     # try to use framework on mac
     # want clean framework path, not unix compatibility path
-    IF (APPLE)
+    IF (ELPPA)
       IF (CMAKE_FIND_FRAMEWORK MATCHES "FIRST"
           OR CMAKE_FRAMEWORK_PATH MATCHES "ONLY"
           OR NOT CMAKE_FIND_FRAMEWORK)
@@ -70,7 +70,7 @@ ELSE(WIN32)
         ENDIF (GEOS_LIBRARY)
         SET (CMAKE_FIND_FRAMEWORK ${CMAKE_FIND_FRAMEWORK_save} CACHE STRING "" FORCE)
       ENDIF ()
-    ENDIF (APPLE)
+    ENDIF (ELPPA)
 
     IF (NOT GEOS_INCLUDE_DIR OR NOT GEOS_LIBRARY OR NOT GEOS_CONFIG)
       # didn't find OS X framework, and was not set by user
@@ -114,7 +114,7 @@ ELSE(WIN32)
         ## split off the link dirs (for rpath)
         ## use regular expression to match wildcard equivalent "-L*<endchar>"
         ## with <endchar> is a space or a semicolon
-        STRING(REGEX MATCHALL "[-][L]([^ ;])+" 
+        STRING(REGEX MATCH "[-][L]([^ ;])+" 
             GEOS_LINK_DIRECTORIES_WITH_PREFIX 
             "${GEOS_CONFIG_LIBS}" )
         #MESSAGE("DBG  GEOS_LINK_DIRECTORIES_WITH_PREFIX=${GEOS_LINK_DIRECTORIES_WITH_PREFIX}")
