$NetBSD: patch-Graphite.cmake,v 1.1 2014/05/16 01:21:12 pho Exp $

CREATE_LIBTOOL_FILE: Fix incorrect library_names on Darwin

--- Graphite.cmake.orig	2014-05-16 01:00:36.000000000 +0000
+++ Graphite.cmake
@@ -46,7 +46,7 @@ FUNCTION(CREATE_LIBTOOL_FILE _target _in
   FILE(APPEND ${_laname} "dlname='${_soname}'\n\n")
   FILE(APPEND ${_laname} "# Names of this library.\n")
   if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
-    FILE(APPEND ${_laname} "library_names='${_lanamwe}.${_target_current}.${_target_revision}.${_target_age}.${_soext} ${_lanamewe}.${_target_current}.${_soext} ${_soname}'\n\n")
+    FILE(APPEND ${_laname} "library_names='${_lanamewe}.${_target_current}.${_target_revision}.${_target_age}${_soext} ${_lanamewe}.${_target_current}${_soext} ${_soname}'\n\n")
   else (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
     FILE(APPEND ${_laname} "library_names='${_soname}.${_target_current}.${_target_revision}.${_target_age} ${_soname}.${_target_current} ${_soname}'\n\n")
   endif (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
