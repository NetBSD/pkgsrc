$NetBSD: patch-aa,v 1.3 2013/07/12 00:07:04 taca Exp $

--- acinclude.m4.orig	2013-07-10 17:43:08.000000000 +0000
+++ acinclude.m4
@@ -2341,7 +2341,7 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   if test "$found_openssl" = "no"; then
   
     if test "$PHP_OPENSSL_DIR" = "yes"; then
-      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl"
+      PHP_OPENSSL_DIR="/usr/local/ssl /usr/local /usr /usr/local/openssl /"
     fi
 
     for i in $PHP_OPENSSL_DIR; do
