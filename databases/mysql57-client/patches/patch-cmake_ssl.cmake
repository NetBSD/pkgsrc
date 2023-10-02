$NetBSD: patch-cmake_ssl.cmake,v 1.6 2023/10/02 10:31:59 adam Exp $

Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2023-06-21 13:02:02.000000000 +0000
+++ cmake/ssl.cmake
@@ -128,6 +128,29 @@ MACRO(FIND_OPENSSL_VERSION)
       OPENSSL_VERSION_NUMBER
       REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
       )
+    IF (NOT OPENSSL_VERSION_NUMBER)
+      FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+        OPENSSL_VERSION_NUMBER
+        REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_MAJOR[\t ]+[0-9].*$"
+      )
+      STRING(REGEX REPLACE "^.*MAJOR[\t ]+([0-9]).*$" "\\1"
+        OPENSSL_MAJOR_VERSION "${OPENSSL_VERSION_NUMBER}"
+      )
+      FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+        OPENSSL_VERSION_NUMBER
+        REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_MINOR[\t ]+[0-9].*"
+      )
+      STRING(REGEX REPLACE "^.*MINOR[\t ]+([0-9]).*$" "\\1"
+        OPENSSL_MINOR_VERSION "${OPENSSL_VERSION_NUMBER}"
+      )
+      FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+        OPENSSL_VERSION_NUMBER
+        REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_PATCH[\t ]+[0-9].*"
+      )
+      STRING(REGEX REPLACE "^.*PATCH[\t ]+([0-9]).*$" "\\1"
+        OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
+      )
+    ELSE()
     STRING(REGEX REPLACE
       "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9]).*$" "\\1"
       OPENSSL_MAJOR_VERSION "${OPENSSL_VERSION_NUMBER}"
@@ -140,6 +163,7 @@ MACRO(FIND_OPENSSL_VERSION)
       "^.*OPENSSL_VERSION_NUMBER[\t ]+0x[0-9][0-9][0-9]([0-9][0-9]).*$" "\\1"
       OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
       )
+    ENDIF()
   ENDIF()
   SET(OPENSSL_VERSION
     "${OPENSSL_MAJOR_VERSION}.${OPENSSL_MINOR_VERSION}.${OPENSSL_FIX_VERSION}"
@@ -235,7 +259,6 @@ MACRO (MYSQL_CHECK_SSL)
     # On mac this list is <.dylib;.so;.a>
     # We prefer static libraries, so we reverse it here.
     IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
       MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     ENDIF()
 
@@ -245,9 +268,6 @@ MACRO (MYSQL_CHECK_SSL)
     FIND_LIBRARY(CRYPTO_LIBRARY
                  NAMES crypto libcrypto libeay32
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR)
       FIND_OPENSSL_VERSION()
@@ -256,7 +276,7 @@ MACRO (MYSQL_CHECK_SSL)
     IF("${OPENSSL_VERSION}" VERSION_GREATER "1.1.0")
        ADD_DEFINITIONS(-DHAVE_TLSv13)
        SET(HAVE_TLSv13 1)
-       IF(SOLARIS)
+       IF(SOLARIS AND CMAKE_C_COMPILER_ID MATCHES "SunPro")
          SET(FORCE_SSL_SOLARIS "-Wl,--undefined,address_of_sk_new_null")
        ENDIF()
     ENDIF()
