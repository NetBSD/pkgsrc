$NetBSD: patch-acinclude.m4,v 1.2 2016/12/05 18:17:11 adam Exp $

On Darwin, allow native iconv when Command Line Tools are not installed.

--- acinclude.m4.orig	2016-11-09 01:22:57.000000000 +0000
+++ acinclude.m4
@@ -2354,7 +2354,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
   
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
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
