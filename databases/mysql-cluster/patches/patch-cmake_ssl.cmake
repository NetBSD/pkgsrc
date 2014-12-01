$NetBSD: patch-cmake_ssl.cmake,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

Allow OpenSSH versions below 1.0.
Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2013-04-05 12:27:18.000000000 +0000
+++ cmake/ssl.cmake
@@ -143,9 +143,7 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
 
     # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we revert it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
     FIND_LIBRARY(OPENSSL_LIBRARY
@@ -172,8 +170,7 @@ MACRO (MYSQL_CHECK_SSL)
 
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
-       CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       CRYPTO_LIBRARY
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
