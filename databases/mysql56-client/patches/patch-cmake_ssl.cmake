$NetBSD: patch-cmake_ssl.cmake,v 1.1 2013/02/13 21:00:04 adam Exp $

Allow OpenSSH versions below 1.0.
Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2013-02-12 13:35:25.000000000 +0000
+++ cmake/ssl.cmake
@@ -139,8 +139,6 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
 
     # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we revert it here.
-    LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
     MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     FIND_LIBRARY(OPENSSL_LIBRARIES
                  NAMES ssl ssleay32 ssleay32MD
@@ -164,8 +162,7 @@ MACRO (MYSQL_CHECK_SSL)
 
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARIES   AND
-       CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       CRYPTO_LIBRARY
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
