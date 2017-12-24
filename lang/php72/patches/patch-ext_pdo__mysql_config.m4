$NetBSD: patch-ext_pdo__mysql_config.m4,v 1.3 2017/12/24 13:37:12 jdolecek Exp $

Reported upstream as #75615

--- ext/pdo_mysql/config.m4.orig	2015-06-23 17:33:33.000000000 +0000
+++ ext/pdo_mysql/config.m4
@@ -156,7 +156,7 @@ if test "$PHP_PDO_MYSQL" != "no"; then
   fi
 
   dnl fix after renaming to pdo_mysql
-  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared,,-I$pdo_cv_inc_path -I -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
+  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared,,-I$pdo_cv_inc_path -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
   ifdef([PHP_ADD_EXTENSION_DEP],
   [
     PHP_ADD_EXTENSION_DEP(pdo_mysql, pdo)
