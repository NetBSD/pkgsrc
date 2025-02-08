$NetBSD: patch-ext_pdo__mysql_config.m4,v 1.2 2025/02/08 02:57:59 taca Exp $

* Do not append empty -I arguments.

--- ext/pdo_mysql/config.m4.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/pdo_mysql/config.m4
@@ -130,8 +130,8 @@ if test "$PHP_PDO_MYSQL" != "no"; then
       pdo_cv_inc_path=$abs_srcdir/ext
     elif test -f $abs_srcdir/ext/pdo/php_pdo_driver.h; then
       pdo_cv_inc_path=$abs_srcdir/ext
-    elif test -f $prefix/include/php/ext/pdo/php_pdo_driver.h; then
-      pdo_cv_inc_path=$prefix/include/php/ext
+    elif test -f $prefix/${PHP_INCDIR}/ext/pdo/php_pdo_driver.h; then
+      pdo_cv_inc_path=$prefix/${PHP_INCDIR}/php/ext
     else
       AC_MSG_ERROR([Cannot find php_pdo_driver.h.])
     fi
@@ -144,7 +144,7 @@ if test "$PHP_PDO_MYSQL" != "no"; then
   fi
 
   dnl fix after renaming to pdo_mysql
-  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared,,-I$pdo_cv_inc_path -I)
+  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared)
   ifdef([PHP_ADD_EXTENSION_DEP],
   [
     PHP_ADD_EXTENSION_DEP(pdo_mysql, pdo)
