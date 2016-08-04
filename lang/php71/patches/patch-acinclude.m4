$NetBSD: patch-acinclude.m4,v 1.1 2016/08/04 14:09:03 jdolecek Exp $

--- acinclude.m4.orig	2015-06-23 17:33:33.000000000 +0000
+++ acinclude.m4
@@ -2354,7 +2354,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
   
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
