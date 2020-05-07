$NetBSD: patch-cmake_ldap.cmake,v 1.1 2020/05/07 05:31:53 adam Exp $

Do not prefer static libraries (or linking will fail).

--- cmake/ldap.cmake.orig	2020-05-06 20:42:06.000000000 +0000
+++ cmake/ldap.cmake
@@ -80,7 +80,6 @@ MACRO(FIND_CUSTOM_LDAP)
 
   # On mac this list is <.dylib;.so;.a>
   # We prefer static libraries, so we reverse it here.
-  LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
 
   FIND_LIBRARY(LDAP_CUSTOM_LIBRARY
     NAMES ldap_r ldap
@@ -97,7 +96,6 @@ MACRO(FIND_CUSTOM_LDAP)
     NO_SYSTEM_ENVIRONMENT_PATH
     )
 
-  LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
 
   IF(LDAP_INCLUDE_DIR)
     INCLUDE_DIRECTORIES(BEFORE SYSTEM ${LDAP_INCLUDE_DIR})
