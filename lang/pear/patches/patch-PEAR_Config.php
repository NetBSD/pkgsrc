$NetBSD: patch-PEAR_Config.php,v 1.1 2025/02/08 03:24:29 taca Exp $

* Add ${PHP_VER} suffix.

--- PEAR/Config.php.orig	2024-03-09 19:35:30.000000000 +0000
+++ PEAR/Config.php
@@ -196,7 +196,7 @@ if (getenv('PHP_PEAR_PHP_BIN')) {
     define('PEAR_CONFIG_DEFAULT_PHP_BIN', getenv('PHP_PEAR_PHP_BIN'));
 } else {
     define('PEAR_CONFIG_DEFAULT_PHP_BIN', PEAR_CONFIG_DEFAULT_BIN_DIR.
-           DIRECTORY_SEPARATOR.'php'.(OS_WINDOWS ? '.exe' : ''));
+           DIRECTORY_SEPARATOR.'php@PHP_VER@'.(OS_WINDOWS ? '.exe' : ''));
 }
 
 // Default for verbose
