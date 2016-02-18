$NetBSD: patch-cmake_modules_FindLdap.cmake,v 1.1 2016/02/18 20:55:45 jperkin Exp $

Support pkgsrc ldap on Darwin.

--- cmake/modules/FindLdap.cmake.orig	2015-06-24 12:43:14.000000000 +0000
+++ cmake/modules/FindLdap.cmake
@@ -14,13 +14,13 @@ endif()
 
 FIND_PATH(LDAP_INCLUDE_DIR ldap.h)
 
-if(APPLE)
+if(notAPPLE)
    FIND_LIBRARY(LDAP_LIBRARIES NAMES LDAP
    	PATHS
    	/System/Library/Frameworks
    	/Library/Frameworks
    )
-else(APPLE)
+else(notAPPLE)
    FIND_LIBRARY(LDAP_LIBRARIES NAMES ldap)
    
    FIND_LIBRARY(LBER_LIBRARIES NAMES lber)
