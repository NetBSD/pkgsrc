$NetBSD: patch-libraries_vendor__config.php,v 1.1 2018/12/10 19:27:46 tm Exp $

As recommended by phpMyAdmin developers the temp directory should not be part of the webroot. User configuration should be also stored in the "etc"-folder to update the package without configuration changes.

--- libraries/vendor_config.php.orig	2018-08-22 13:36:50.000000000 +0000
+++ libraries/vendor_config.php
@@ -22,7 +22,7 @@ define('AUTOLOAD_FILE', './vendor/autolo
 /**
  * Directory where cache files are stored.
  */
-define('TEMP_DIR', './tmp/');
+define('TEMP_DIR', '@PMVARDIR@/tmp/');

 /**
  * Path to changelog file, can be gzip compressed. Useful when you want to
@@ -46,7 +46,7 @@ define('SQL_DIR', './sql/');
  * It is not used directly in code, just a convenient
  * define used further in this file.
  */
-define('CONFIG_DIR', '');
+define('CONFIG_DIR', '@PMCONFDIR@');

 /**
  * Filename of a configuration file.
