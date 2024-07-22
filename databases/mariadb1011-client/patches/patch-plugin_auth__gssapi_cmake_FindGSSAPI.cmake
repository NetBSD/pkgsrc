$NetBSD: patch-plugin_auth__gssapi_cmake_FindGSSAPI.cmake,v 1.1 2024/07/22 19:26:30 adam Exp $

Use pkgsrc provided krb5-config.

--- plugin/auth_gssapi/cmake/FindGSSAPI.cmake.orig	2024-07-22 18:49:17.598571330 +0000
+++ plugin/auth_gssapi/cmake/FindGSSAPI.cmake
@@ -39,10 +39,6 @@ if(GSSAPI_LIBS AND GSSAPI_FLAVOR)
 
 else(GSSAPI_LIBS AND GSSAPI_FLAVOR)
 
-  find_program(KRB5_CONFIG NAMES krb5-config heimdal-krb5-config PATHS
-     /opt/local/bin /usr/lib/mit/bin
-     ONLY_CMAKE_FIND_ROOT_PATH               # this is required when cross compiling with cmake 2.6 and ignored with cmake 2.4, Alex
-  )
   mark_as_advanced(KRB5_CONFIG)
 
   #reset vars
