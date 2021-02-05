$NetBSD: patch-cmake_ssl.cmake,v 1.4 2021/02/05 09:28:07 adam Exp $

Allow OpenSSH versions below 1.0.
Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2021-01-05 10:19:59.000000000 +0000
+++ cmake/ssl.cmake
@@ -154,7 +154,6 @@ MACRO (MYSQL_CHECK_SSL)
     # On mac this list is <.dylib;.so;.a>
     # We prefer static libraries, so we revert it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
 
@@ -164,9 +163,6 @@ MACRO (MYSQL_CHECK_SSL)
     FIND_LIBRARY(CRYPTO_LIBRARY
                  NAMES crypto libcrypto libeay32
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR)
       # Verify version number. Version information looks like:
@@ -194,8 +190,7 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
-       CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       CRYPTO_LIBRARY
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
