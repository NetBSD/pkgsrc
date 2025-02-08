$NetBSD: patch-build_php.m4,v 1.2 2025/02/08 02:58:55 taca Exp $

* Adjust PHP library name.
* Do not include "PKG_CONFIG*" in CONFIGURE_OPTIONS.

--- build/php.m4.orig	2022-10-31 10:36:05.000000000 +0000
+++ build/php.m4
@@ -768,7 +768,7 @@ dnl PHP_BUILD_SHARED
 dnl
 AC_DEFUN([PHP_BUILD_SHARED],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp[]$PHP_MAJOR_VERSION[.la]
+  OVERALL_TARGET=libphp[]$PHP_VER[.la]
   php_sapi_module=shared
 
   php_c_pre=$shared_c_pre
@@ -785,7 +785,7 @@ dnl PHP_BUILD_STATIC
 dnl
 AC_DEFUN([PHP_BUILD_STATIC],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp[]$PHP_MAJOR_VERSION[.la]
+  OVERALL_TARGET=libphp[]$PHP_VER[.la]
   php_sapi_module=static
 ])
 
@@ -794,7 +794,7 @@ dnl PHP_BUILD_BUNDLE
 dnl
 AC_DEFUN([PHP_BUILD_BUNDLE],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libs/libphp[]$PHP_MAJOR_VERSION[.bundle]
+  OVERALL_TARGET=libs/libphp[]$PHP_VER[.bundle]
   php_sapi_module=static
 ])
 
@@ -2151,6 +2151,10 @@ EOF
    else
     break
    fi
+   case "$CURRENT_ARG" in
+       \'PKG_CONFIG\=*)	CURRENT_ARG="'PKG_CONFIG=@TOOLS_PATH.pkg-config@'";;
+       \'PKG_CONFIG_LIBDIR\=*)	CURRENT_ARG="'PKG_CONFIG_LIBDIR=@PHP_PKGCONFIG_PATH@'";;
+   esac
    $as_echo "$CURRENT_ARG \\" >>$1
    CONFIGURE_OPTIONS="$CONFIGURE_OPTIONS $CURRENT_ARG"
   done
