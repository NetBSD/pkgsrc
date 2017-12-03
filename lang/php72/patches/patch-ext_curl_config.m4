$NetBSD: patch-ext_curl_config.m4,v 1.2 2017/12/03 12:22:59 jdolecek Exp $

Reported upstream as #75614

--- ext/curl/config.m4.orig	2017-11-15 10:50:33.000000000 +0000
+++ ext/curl/config.m4
@@ -14,7 +14,7 @@ if test "$PHP_CURL" != "no"; then
     dnl using pkg-config output
 
     AC_MSG_CHECKING(for libcurl.pc)
-    if test "$PHP_CURL" == "yes" -o "$PHP_CURL" == "/usr"; then
+    if test "$PHP_CURL" = "yes" -o "$PHP_CURL" = "/usr"; then
       PKNAME=libcurl
       AC_MSG_RESULT(using default path)
     elif test -r $PHP_CURL/$PHP_LIBDIR/pkgconfig/libcurl.pc; then
