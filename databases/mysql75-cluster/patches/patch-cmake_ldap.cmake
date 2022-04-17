$NetBSD: patch-cmake_ldap.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- cmake/ldap.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ cmake/ldap.cmake
@@ -79,8 +79,6 @@ MACRO(FIND_CUSTOM_LDAP)
     )
 
   # On mac this list is <.dylib;.so;.a>
-  # We prefer static libraries, so we reverse it here.
-  LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
 
   FIND_LIBRARY(LDAP_CUSTOM_LIBRARY
     NAMES ldap_r ldap
@@ -97,8 +95,6 @@ MACRO(FIND_CUSTOM_LDAP)
     NO_SYSTEM_ENVIRONMENT_PATH
     )
 
-  LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-
   IF(LDAP_INCLUDE_DIR)
     INCLUDE_DIRECTORIES(BEFORE SYSTEM ${LDAP_INCLUDE_DIR})
 
