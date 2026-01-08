$NetBSD: patch-sapi_cgi_config9.m4,v 1.1 2026/01/08 13:38:00 taca Exp $

* Add $PHP_VER suffix.

--- sapi/cgi/config9.m4.orig	2025-01-15 01:03:17.000000000 +0000
+++ sapi/cgi/config9.m4
@@ -22,8 +22,8 @@ if test "$PHP_CGI" != "no"; then
 
   dnl Set filename.
   AS_CASE([$host_alias],
-    [*cygwin*], [SAPI_CGI_PATH=sapi/cgi/php-cgi.exe],
-    [SAPI_CGI_PATH=sapi/cgi/php-cgi])
+    [*cygwin*], [SAPI_CGI_PATH=sapi/cgi/php${PHP_VER}-cgi.exe],
+    [SAPI_CGI_PATH=sapi/cgi/php${PHP_VER}-cgi])
 
   dnl Select SAPI.
   PHP_SELECT_SAPI([cgi],
