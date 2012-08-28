$NetBSD: patch-libraries_vendor_config.php,v 1.2 2012/08/28 15:54:54 tron Exp $

Configure location of the configuration file in the vendor specific section
as suggested by the phpMyAdmin documentation.

--- libraries/vendor_config.php.orig	2012-08-12 14:45:56.000000000 +0100
+++ libraries/vendor_config.php	2012-08-28 16:44:12.000000000 +0100
@@ -25,7 +25,7 @@
 /**
  * Path to config file generated using setup script.
  */
-define('SETUP_CONFIG_FILE', './config/config.inc.php');
+define('SETUP_CONFIG_FILE', '@@PMSETUPFILE@@');
 
 /**
  * Whether setup requires writable directory where config
