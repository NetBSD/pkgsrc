$NetBSD: patch-libraries_vendor_config.php,v 1.3 2013/09/18 22:20:04 tron Exp $

Configure location of the configuration file in the vendor specific section
as suggested by the phpMyAdmin documentation.

--- libraries/vendor_config.php.orig	2013-09-05 17:34:46.000000000 +0100
+++ libraries/vendor_config.php	2013-09-18 21:07:38.000000000 +0100
@@ -28,7 +28,7 @@
 /**
  * Path to config file generated using setup script.
  */
-define('SETUP_CONFIG_FILE', './config/config.inc.php');
+define('SETUP_CONFIG_FILE', '@@PMSETUPFILE@@');
 
 /**
  * Whether setup requires writable directory where config
