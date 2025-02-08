$NetBSD: patch-acinclude.m4,v 1.3 2025/02/08 02:57:59 taca Exp $

* Adjust PHP directories.
* Adjust PHP library name.
* On Darwin, allow native iconv when Command Line Tools are not installed.

--- acinclude.m4.orig	2019-01-09 09:54:13.000000000 +0000
+++ acinclude.m4
@@ -143,7 +143,7 @@ test -d include || $php_shtool mkdir inc
 > Makefile.fragments
 dnl We need to play tricks here to avoid matching the grep line itself
 pattern=define
-$EGREP $pattern'.*include/php' $srcdir/configure|$SED 's/.*>//'|xargs touch 2>/dev/null
+$EGREP $pattern'.*'${PHP_INCDIR} $srcdir/configure|$SED 's/.*>//'|xargs touch 2>/dev/null
 ])
 
 dnl
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
 
@@ -2488,7 +2488,15 @@ AC_DEFUN([PHP_SETUP_ICONV], [
     done
 
     if test -z "$ICONV_DIR"; then
+    case $host_alias in
+    *darwin*)
+      ICONV_DIR=/usr
+      iconv_lib_name=iconv
+      ;;
+    *)
       AC_MSG_ERROR([Please specify the install prefix of iconv with --with-iconv=<DIR>])
+      ;;
+    esac
     fi
   
     if test -f $ICONV_DIR/$PHP_LIBDIR/lib$iconv_lib_name.a ||
@@ -2771,8 +2779,8 @@ AC_DEFUN([PHP_CHECK_PDO_INCLUDES],[
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
