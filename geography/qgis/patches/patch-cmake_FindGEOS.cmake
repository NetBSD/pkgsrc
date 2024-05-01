$NetBSD: patch-cmake_FindGEOS.cmake,v 1.4 2024/05/01 12:46:59 adam Exp $

On Darwin, don't look for frameworks.

--- cmake/FindGEOS.cmake.orig	2024-04-28 20:01:10.892394080 +0000
+++ cmake/FindGEOS.cmake
@@ -40,7 +40,7 @@ ELSE(WIN32)
  IF(UNIX)
     # try to use framework on mac
     # want clean framework path, not unix compatibility path
-    IF (APPLE)
+    IF (FALSE)
       IF (CMAKE_FIND_FRAMEWORK MATCHES "FIRST"
           OR CMAKE_FRAMEWORK_PATH MATCHES "ONLY"
           OR NOT CMAKE_FIND_FRAMEWORK)
