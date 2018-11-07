$NetBSD: patch-build_cmake_version.cmake,v 1.1 2018/11/07 13:08:29 ryoon Exp $

--- build/cmake/version.cmake.orig	2018-10-01 03:20:05.000000000 +0000
+++ build/cmake/version.cmake
@@ -36,7 +36,7 @@ if(EXISTS "${GIT_EXECUTABLE}")
 endif()
 
 if("${aom_version}" STREQUAL "")
-  set(aom_version "${AOM_ROOT}/CHANGELOG")
+  set(aom_version "@PKGVERSION_NOREV@")
 endif()
 
 unset(last_aom_version)
