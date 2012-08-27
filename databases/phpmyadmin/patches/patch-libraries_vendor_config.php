$NetBSD: patch-libraries_vendor_config.php,v 1.1 2012/08/27 17:11:34 tron Exp $

Configure location of the configuration file in the vendor specific section
as suggested by the phpMyAdmin documentation.

--- libraries/vendor_config.php.orig	2012-08-12 14:45:56.000000000 +0100
+++ libraries/vendor_config.php	2012-08-27 17:59:25.000000000 +0100
@@ -25,13 +25,13 @@
 /**
  * Path to config file generated using setup script.
  */
-define('SETUP_CONFIG_FILE', './config/config.inc.php');
+define('SETUP_CONFIG_FILE', '@@PMCONFFILE@@');
 
 /**
  * Whether setup requires writable directory where config
  * file will be generated.
  */
-define('SETUP_DIR_WRITABLE', true);
+define('SETUP_DIR_WRITABLE', false);
 
 /**
  * Directory where configuration files are stored.
