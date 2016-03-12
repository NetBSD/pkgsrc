$NetBSD: patch-config.m4,v 1.1 2016/03/12 09:39:57 fhajny Exp $

Make sure configure can find our curl.

--- config.m4.orig	1970-01-01 09:13:08.000000000 +0000
+++ config.m4
@@ -5,6 +5,9 @@ dnl
 PHP_ARG_ENABLE(oauth, for oauth support,
 [  --enable-oauth          Include oauth support])
 
+PHP_ARG_WITH([curl], [whether to enable cURL engine support],
+[  --with-curl[=PATH]      Include cURL engine support], $PHP_OAUTH, $PHP_OAUTH)
+
 if test "$PHP_OAUTH" != "no"; then
   PHP_SUBST(OAUTH_SHARED_LIBADD)
 
@@ -12,7 +15,7 @@ if test "$PHP_OAUTH" != "no"; then
   CFLAGS="$CFLAGS -Wall -g"
 
   AC_MSG_CHECKING(for cURL in default path)
-  for i in /usr/local /usr; do
+  for i in "$PHP_CURL" /usr/local /usr; do
     if test -r $i/include/curl/easy.h; then
       CURL_DIR=$i
       AC_MSG_RESULT(found in $i)
