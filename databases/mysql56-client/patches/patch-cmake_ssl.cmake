$NetBSD: patch-cmake_ssl.cmake,v 1.3 2019/10/14 19:44:47 adam Exp $

Allow OpenSSH versions below 1.0.
Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2019-09-27 07:04:56.000000000 +0000
+++ cmake/ssl.cmake
@@ -152,9 +152,7 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
 
     # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we revert it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
 
@@ -194,8 +192,7 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
-       CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       CRYPTO_LIBRARY
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
