$NetBSD: patch-cmake_ssl.cmake,v 1.5 2021/11/10 11:03:52 jperkin Exp $

Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2021-09-07 05:26:47.000000000 +0000
+++ cmake/ssl.cmake
@@ -153,7 +153,6 @@ MACRO (MYSQL_CHECK_SSL)
     # On mac this list is <.dylib;.so;.a>
     # We prefer static libraries, so we reverse it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
 
@@ -163,9 +162,6 @@ MACRO (MYSQL_CHECK_SSL)
     FIND_LIBRARY(CRYPTO_LIBRARY
                  NAMES crypto libcrypto libeay32
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR)
       # Verify version number. Version information looks like:
@@ -175,6 +171,29 @@ MACRO (MYSQL_CHECK_SSL)
         OPENSSL_VERSION_NUMBER
         REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
         )
+      IF (NOT OPENSSL_VERSION_NUMBER)
+        FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+          OPENSSL_VERSION_NUMBER
+          REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_MAJOR[\t ]+[0-9].*$"
+        )
+        STRING(REGEX REPLACE "^.*MAJOR[\t ]+([0-9]).*$" "\\1"
+          OPENSSL_MAJOR_VERSION "${OPENSSL_VERSION_NUMBER}"
+        )
+        FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+          OPENSSL_VERSION_NUMBER
+          REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_MINOR[\t ]+[0-9].*"
+        )
+        STRING(REGEX REPLACE "^.*MINOR[\t ]+([0-9]).*$" "\\1"
+          OPENSSL_MINOR_VERSION "${OPENSSL_VERSION_NUMBER}"
+        )
+        FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+          OPENSSL_VERSION_NUMBER
+          REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_PATCH[\t ]+[0-9].*"
+        )
+        STRING(REGEX REPLACE "^.*PATCH[\t ]+([0-9]).*$" "\\1"
+          OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
+        )
+      ELSE()
       STRING(REGEX REPLACE
         "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9]).*$" "\\1"
         OPENSSL_MAJOR_VERSION "${OPENSSL_VERSION_NUMBER}"
@@ -187,6 +206,7 @@ MACRO (MYSQL_CHECK_SSL)
         "^.*OPENSSL_VERSION_NUMBER[\t ]+0x[0-9][0-9][0-9]([0-9][0-9]).*$" "\\1"
         OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
         )
+      ENDIF()
     ENDIF()
     SET(OPENSSL_VERSION
       "${OPENSSL_MAJOR_VERSION}.${OPENSSL_MINOR_VERSION}.${OPENSSL_FIX_VERSION}"
@@ -196,14 +216,14 @@ MACRO (MYSQL_CHECK_SSL)
     IF("${OPENSSL_VERSION}" VERSION_GREATER "1.1.0")
        ADD_DEFINITIONS(-DHAVE_TLSv13)
        SET(HAVE_TLSv13 1)
-       IF(SOLARIS)
+       IF(SOLARIS AND CMAKE_C_COMPILER_ID MATCHES "SunPro")
          SET(FORCE_SSL_SOLARIS "-Wl,--undefined,address_of_sk_new_null")
        ENDIF()
     ENDIF()
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
        CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       (OPENSSL_MAJOR_VERSION STREQUAL "1" OR OPENSSL_MAJOR_VERSION STREQUAL "3")
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
