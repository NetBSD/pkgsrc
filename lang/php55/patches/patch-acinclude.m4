$NetBSD: patch-acinclude.m4,v 1.2 2013/08/17 13:15:21 taca Exp $

--- acinclude.m4.orig	2013-08-15 20:42:04.000000000 +0000
+++ acinclude.m4
@@ -2354,7 +2354,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
   
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
