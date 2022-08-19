$NetBSD: patch-program_include_iniset.php,v 1.1 2022/08/19 13:09:38 taca Exp $

Honor PKG_SYSCONFDIR.

--- program/include/iniset.php.orig	2022-07-23 20:17:14.000000000 +0000
+++ program/include/iniset.php
@@ -32,7 +32,7 @@ if (!defined('INSTALL_PATH')) {
 }
 
 if (!defined('RCMAIL_CONFIG_DIR')) {
-    define('RCMAIL_CONFIG_DIR', getenv('ROUNDCUBE_CONFIG_DIR') ?: (INSTALL_PATH . 'config'));
+    define('RCMAIL_CONFIG_DIR', getenv('ROUNDCUBE_CONFIG_DIR') ?: '@PKG_SYSCONFDIR@');
 }
 
 if (!defined('RCUBE_LOCALIZATION_DIR')) {
