$NetBSD: patch-build_php.m4,v 1.1 2025/02/22 15:27:56 taca Exp $

* Do not include "PKG_CONFIG*" in CONFIGURE_OPTIONS.
* Add ${PHP_VER} suffix.
* Fake required zlib version for NetBSD.

--- build/php.m4.orig	2025-01-15 01:03:17.000000000 +0000
+++ build/php.m4
@@ -767,7 +767,7 @@ dnl PHP_BUILD_SHARED
 dnl
 AC_DEFUN([PHP_BUILD_SHARED],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp.la
+  OVERALL_TARGET=libphp$PHP_VER.la
   php_sapi_module=shared
 
   php_c_pre=$shared_c_pre
@@ -784,7 +784,7 @@ dnl PHP_BUILD_STATIC
 dnl
 AC_DEFUN([PHP_BUILD_STATIC],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp.la
+  OVERALL_TARGET=libphp$PHP_VER.la
   php_sapi_module=static
 ])
 
@@ -793,7 +793,7 @@ dnl PHP_BUILD_BUNDLE
 dnl
 AC_DEFUN([PHP_BUILD_BUNDLE],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libs/libphp.bundle
+  OVERALL_TARGET=libs/libphp$PHP_VER.bundle
   php_sapi_module=static
 ])
 
@@ -1928,7 +1928,7 @@ dnl default error by PKG_CHECK_MODULES i
 dnl is given.
 dnl
 AC_DEFUN([PHP_SETUP_ZLIB], [dnl
-PKG_CHECK_MODULES([ZLIB], [zlib >= 1.2.11], [dnl
+PKG_CHECK_MODULES([ZLIB], [zlib >= @FAKE_ZLIB_VERSION@], [dnl
   PHP_EVAL_INCLINE([$ZLIB_CFLAGS])
   PHP_EVAL_LIBLINE([$ZLIB_LIBS], [$1])
   $2], [$3])dnl
@@ -2099,6 +2099,10 @@ EOF
    else
     break
    fi
+   case "$CURRENT_ARG" in
+       \'PKG_CONFIG\=*)	CURRENT_ARG="'PKG_CONFIG=@TOOLS_PATH.pkg-config@'";;
+       \'PKG_CONFIG_LIBDIR\=*)	CURRENT_ARG="'PKG_CONFIG_LIBDIR=@PHP_PKGCONFIG_PATH@'";;
+   esac
    AS_ECHO(["$CURRENT_ARG \\"]) >>$1
    CONFIGURE_OPTIONS="$CONFIGURE_OPTIONS $CURRENT_ARG"
   done
