$NetBSD: patch-aclocal.m4,v 1.3 2025/02/08 02:57:59 taca Exp $

* Adjust PHP directories.
* Adjust PHP library name.

--- aclocal.m4.orig	2019-01-09 10:25:55.000000000 +0000
+++ aclocal.m4
@@ -772,7 +772,7 @@ dnl PHP_BUILD_SHARED
 dnl
 AC_DEFUN([PHP_BUILD_SHARED],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp[]$PHP_MAJOR_VERSION[.la]
+  OVERALL_TARGET=libphp[]$PHP_VER[.la]
   php_sapi_module=shared
   
   php_c_pre=$shared_c_pre
@@ -789,7 +789,7 @@ dnl PHP_BUILD_STATIC
 dnl
 AC_DEFUN([PHP_BUILD_STATIC],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libphp[]$PHP_MAJOR_VERSION[.la]
+  OVERALL_TARGET=libphp[]$PHP_VER[.la]
   php_sapi_module=static
 ])
 
@@ -798,7 +798,7 @@ dnl PHP_BUILD_BUNDLE
 dnl
 AC_DEFUN([PHP_BUILD_BUNDLE],[
   PHP_BUILD_PROGRAM
-  OVERALL_TARGET=libs/libphp[]$PHP_MAJOR_VERSION[.bundle]
+  OVERALL_TARGET=libs/libphp[]$PHP_VER[.bundle]
   php_sapi_module=static
 ])
 
@@ -2771,8 +2771,8 @@ AC_DEFUN([PHP_CHECK_PDO_INCLUDES],[
       pdo_cv_inc_path=$abs_srcdir/ext
     elif test -f $abs_srcdir/ext/pdo/php_pdo_driver.h; then
       pdo_cv_inc_path=$abs_srcdir/ext
-    elif test -f $prefix/include/php/ext/pdo/php_pdo_driver.h; then
-      pdo_cv_inc_path=$prefix/include/php/ext
+    elif test -f $prefix/${PHP_INCDIR}/ext/pdo/php_pdo_driver.h; then
+      pdo_cv_inc_path=$prefix/${PHP_INCDIR}/ext
     fi
   ])
   if test -n "$pdo_cv_inc_path"; then
