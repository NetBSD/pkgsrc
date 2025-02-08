$NetBSD: patch-build_php.m4,v 1.2 2025/02/08 02:59:45 taca Exp $

* Do not include "PKG_CONFIG*" in CONFIGURE_OPTIONS.
* Adjust PHP library name.

--- build/php.m4.orig	2024-12-17 11:39:23.000000000 +0000
+++ build/php.m4
@@ -752,7 +752,7 @@ dnl PHP_BUILD_SHARED
 dnl
 AC_DEFUN([PHP_BUILD_SHARED],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp.la
+  OVERALL_TARGET=libphp$PHP_VER.la
   php_sapi_module=shared
 
   php_c_pre=$shared_c_pre
@@ -769,7 +769,7 @@ dnl PHP_BUILD_STATIC
 dnl
 AC_DEFUN([PHP_BUILD_STATIC],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp.la
+  OVERALL_TARGET=libphp$PHP_VER.la
   php_sapi_module=static
 ])
 
@@ -778,7 +778,7 @@ dnl PHP_BUILD_BUNDLE
 dnl
 AC_DEFUN([PHP_BUILD_BUNDLE],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libs/libphp.bundle
+  OVERALL_TARGET=libs/libphp$PHP_VER.bundle
   php_sapi_module=static
 ])
 
@@ -2139,6 +2139,10 @@ EOF
    else
     break
    fi
+   case "$CURRENT_ARG" in
+      \'PKG_CONFIG\=*)	CURRENT_ARG="'PKG_CONFIG=@TOOLS_PATH.pkg-config@'";;
+      \'PKG_CONFIG_LIBDIR\=*)	CURRENT_ARG="'PKG_CONFIG_LIBDIR=@PHP_PKGCONFIG_PATH@'";;
+   esac
    AS_ECHO(["$CURRENT_ARG \\"]) >>$1
    CONFIGURE_OPTIONS="$CONFIGURE_OPTIONS $CURRENT_ARG"
   done
