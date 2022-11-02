$NetBSD: patch-cmake_ldap.cmake,v 1.1 2022/11/02 17:02:10 jperkin Exp $

Disable hardcoded system paths.

--- cmake/ldap.cmake.orig	2022-09-13 16:15:16.000000000 +0000
+++ cmake/ldap.cmake
@@ -70,7 +70,7 @@ MACRO(FIND_SYSTEM_LDAP)
     CMAKE_PUSH_CHECK_STATE()
 
     # For Solaris 11.3 we need to explicitly search here:
-    IF(SOLARIS)
+    IF(0)
       INCLUDE_DIRECTORIES(BEFORE SYSTEM /usr/include/openldap)
       SET(CMAKE_REQUIRED_INCLUDES "/usr/include/openldap")
     ENDIF()
