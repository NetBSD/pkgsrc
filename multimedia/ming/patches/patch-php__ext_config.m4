$NetBSD: patch-php__ext_config.m4,v 1.1 2025/02/08 03:48:15 taca Exp $

* Assume math(3) is alwasy available.
* Looking for libming in ${PREFIX}.

--- php_ext/config.m4.orig	2017-04-07 08:12:56.000000000 +0000
+++ php_ext/config.m4
@@ -8,10 +8,10 @@ PHP_ARG_WITH(ming, for MING support,
 [  --with-ming[=DIR]       Include MING support])
 
 if test "$PHP_MING" != "no"; then
-  AC_CHECK_LIB(m, sin)
+  LIBS=-lm
 
   for i in $PHP_MING ../../src /usr/local /usr; do
-    if test -f $i/$PHP_LIBDIR/libming.$SHLIB_SUFFIX_NAME || test -f $i/$PHP_LIBDIR/libming.a; then
+    if test -f $i/lib/libming.$SHLIB_SUFFIX_NAME || test -f $i/lib/libming.a; then
       MING_DIR=$i
       break
     fi
