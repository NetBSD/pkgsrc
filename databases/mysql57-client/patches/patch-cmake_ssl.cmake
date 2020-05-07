$NetBSD: patch-cmake_ssl.cmake,v 1.4 2020/05/07 05:31:53 adam Exp $

Do not prefer static libraries (or linking will fail).

--- cmake/ssl.cmake.orig	2020-03-23 17:35:17.000000000 +0000
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
@@ -196,7 +192,7 @@ MACRO (MYSQL_CHECK_SSL)
     IF("${OPENSSL_VERSION}" VERSION_GREATER "1.1.0")
        ADD_DEFINITIONS(-DHAVE_TLSv13)
        SET(HAVE_TLSv13 1)
-       IF(SOLARIS)
+       IF(SOLARIS AND CMAKE_C_COMPILER_ID MATCHES "SunPro")
          SET(FORCE_SSL_SOLARIS "-Wl,--undefined,address_of_sk_new_null")
        ENDIF()
     ENDIF()
