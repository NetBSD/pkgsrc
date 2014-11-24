$NetBSD: patch-acinclude.m4,v 1.1 2014/11/24 15:37:08 taca Exp $

--- acinclude.m4.orig	2014-11-12 13:52:21.000000000 +0000
+++ acinclude.m4
@@ -2354,7 +2354,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
   
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
