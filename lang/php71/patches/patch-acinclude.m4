$NetBSD: patch-acinclude.m4,v 1.2 2018/11/08 13:59:11 taca Exp $

--- acinclude.m4.orig	2018-11-07 15:35:26.000000000 +0000
+++ acinclude.m4
@@ -2361,7 +2361,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
 
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
