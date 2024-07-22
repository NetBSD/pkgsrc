$NetBSD: patch-libmariadb_cmake_FindGSSAPI.cmake,v 1.1 2024/07/22 19:26:30 adam Exp $

Use pkgsrc provided krb5-config.

--- libmariadb/cmake/FindGSSAPI.cmake.orig	2024-07-22 18:44:49.199556247 +0000
+++ libmariadb/cmake/FindGSSAPI.cmake
@@ -46,11 +46,6 @@ if(GSSAPI_LIBS AND GSSAPI_FLAVOR)
 
 else(GSSAPI_LIBS AND GSSAPI_FLAVOR)
 
-  find_program(KRB5_CONFIG NAMES krb5-config PATHS
-     /opt/local/bin
-     /usr/lib/mit/bin/
-     ONLY_CMAKE_FIND_ROOT_PATH               # this is required when cross compiling with cmake 2.6 and ignored with cmake 2.4, Alex
-  )
   mark_as_advanced(KRB5_CONFIG)
 
   #reset vars
