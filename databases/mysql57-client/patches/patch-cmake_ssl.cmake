$NetBSD: patch-cmake_ssl.cmake,v 1.3 2020/03/17 18:33:08 adam Exp $

Allow OpenSSH versions below 1.0.
Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2019-12-18 12:59:40.000000000 +0000
+++ cmake/ssl.cmake
@@ -149,9 +149,7 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
 
     # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we reverse it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
 
@@ -189,14 +187,13 @@ MACRO (MYSQL_CHECK_SSL)
     IF("${OPENSSL_MAJOR_VERSION}.${OPENSSL_MINOR_VERSION}.${OPENSSL_FIX_VERSION}" VERSION_GREATER "1.1.0")
        ADD_DEFINITIONS(-DHAVE_TLSv13)
        SET(HAVE_TLSv13 1)
-       IF(SOLARIS)
+       IF(SOLARIS AND CMAKE_C_COMPILER_ID MATCHES "SunPro")
          SET(FORCE_SSL_SOLARIS "-Wl,--undefined,address_of_sk_new_null")
        ENDIF()
     ENDIF()
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
-       CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       CRYPTO_LIBRARY
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
