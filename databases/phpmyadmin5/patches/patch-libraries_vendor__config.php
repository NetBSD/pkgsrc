$NetBSD: patch-libraries_vendor__config.php,v 1.1 2022/04/22 19:28:59 tm Exp $

As recommended by phpMyAdmin developers the temp directory should not be part of the webroot. User configuration should be also stored in the "etc"-folder to update the package without configuration changes.

--- libraries/vendor_config.php.orig	2022-02-11 04:16:06.000000000 +0000
+++ libraries/vendor_config.php
@@ -24,7 +24,7 @@ define('AUTOLOAD_FILE', ROOT_PATH . 'ven
 /**
  * Directory where cache files are stored.
  */
-define('TEMP_DIR', ROOT_PATH . 'tmp' . DIRECTORY_SEPARATOR);
+define('TEMP_DIR', '@PMVARDIR@' . DIRECTORY_SEPARATOR . 'tmp' . DIRECTORY_SEPARATOR);
 
 /**
  * Path to changelog file, can be gzip compressed. Useful when you want to
@@ -48,7 +48,7 @@ define('SQL_DIR', ROOT_PATH . 'sql' . DI
  * It is not used directly in code, just a convenient
  * define used further in this file.
  */
-define('CONFIG_DIR', ROOT_PATH);
+define('CONFIG_DIR', '@PMCONFDIR@');
 
 /**
  * Filename of a configuration file.
