$NetBSD: patch-cmake_FindGDAL.cmake,v 1.3 2024/05/01 12:46:59 adam Exp $

On Darwin, don't look for frameworks.

--- cmake/FindGDAL.cmake.orig	2024-04-28 21:33:17.896765468 +0000
+++ cmake/FindGDAL.cmake
@@ -44,7 +44,7 @@ ELSE(WIN32)
 
     # try to use framework on mac
     # want clean framework path, not unix compatibility path
-    IF (APPLE)
+    IF (FALSE)
       IF (CMAKE_FIND_FRAMEWORK MATCHES "FIRST"
           OR CMAKE_FRAMEWORK_PATH MATCHES "ONLY"
           OR NOT CMAKE_FIND_FRAMEWORK)
