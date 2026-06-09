$NetBSD: patch-libmariadb_cmake_FindGSSAPI.cmake,v 1.3 2026/06/09 16:28:09 nia Exp $

Use pkgsrc provided krb5-config.

--- libmariadb/cmake/FindGSSAPI.cmake.orig	2026-05-24 09:58:33.000000000 +0000
+++ libmariadb/cmake/FindGSSAPI.cmake
@@ -46,11 +46,6 @@ else()
 
 else()
 
-  find_program(KRB5_CONFIG NAMES krb5-config PATHS
-     /opt/local/bin
-     /usr/lib/mit/bin/
-     ONLY_CMAKE_FIND_ROOT_PATH               # this is required when cross compiling with cmake 2.6 and ignored with cmake 2.4, Alex
-  )
   mark_as_advanced(KRB5_CONFIG)
 
   #reset vars
