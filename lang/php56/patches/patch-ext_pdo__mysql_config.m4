$NetBSD: patch-ext_pdo__mysql_config.m4,v 1.1 2014/11/24 15:37:08 taca Exp $

--- ext/pdo_mysql/config.m4.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/pdo_mysql/config.m4
@@ -144,7 +144,7 @@ if test "$PHP_PDO_MYSQL" != "no"; then
   fi
 
   dnl fix after renaming to pdo_mysql
-  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared,,-I$pdo_cv_inc_path -I)
+  PHP_NEW_EXTENSION(pdo_mysql, pdo_mysql.c mysql_driver.c mysql_statement.c, $ext_shared)
   ifdef([PHP_ADD_EXTENSION_DEP],
   [
     PHP_ADD_EXTENSION_DEP(pdo_mysql, pdo)
