$NetBSD: patch-sapi_cgi_config9.m4,v 1.1 2025/02/08 02:59:57 taca Exp $

* Adjust PHP directories.

--- sapi/cgi/config9.m4.orig	2024-12-17 18:18:02.000000000 +0000
+++ sapi/cgi/config9.m4
@@ -33,10 +33,10 @@ if test "$PHP_CGI" != "no"; then
     dnl Set filename.
     case $host_alias in
       *cygwin* )
-        SAPI_CGI_PATH=sapi/cgi/php-cgi.exe
+        SAPI_CGI_PATH=sapi/cgi/php-cgi$PHP_VER.exe
         ;;
       * )
-        SAPI_CGI_PATH=sapi/cgi/php-cgi
+        SAPI_CGI_PATH=sapi/cgi/php-cgi$PHP_VER
         ;;
     esac
 
