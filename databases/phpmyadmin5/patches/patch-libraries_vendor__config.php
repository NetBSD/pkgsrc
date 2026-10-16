$NetBSD: patch-libraries_vendor__config.php,v 1.2 2026/10/16 10:38:19 tm Exp $

As recommended by phpMyAdmin developers the temp directory should not be part 
of the webroot. User configuration should be also stored in the "etc"-folder
to update the package without configuration changes.

--- libraries/vendor_config.php.orig	2025-10-07 20:40:11.000000000 +0000
+++ libraries/vendor_config.php
@@ -22,7 +22,7 @@ return [
     /**
      * Directory where cache files are stored.
      */
-    'tempDir' => ROOT_PATH . 'tmp' . DIRECTORY_SEPARATOR,
+    'tempDir' => '@PMVARDIR@' . DIRECTORY_SEPARATOR . 'tmp' . DIRECTORY_SEPARATOR,
 
     /**
      * Path to changelog file, can be gzip compressed.
@@ -43,22 +43,22 @@ return [
     /**
      * Filename of a configuration file.
      */
-    'configFile' => ROOT_PATH . 'config.inc.php',
+    'configFile' => '@PMCONFDIR@' . DIRECTORY_SEPARATOR . 'config.inc.php',
 
     /**
      * Filename of custom header file.
      */
-    'customHeaderFile' => ROOT_PATH . 'config.header.inc.php',
+    'customHeaderFile' => '@PMCONFDIR@' . DIRECTORY_SEPARATOR . 'config.header.inc.php',
 
     /**
      * Filename of custom footer file.
      */
-    'customFooterFile' => ROOT_PATH . 'config.footer.inc.php',
+    'customFooterFile' => '@PMCONFDIR@' . DIRECTORY_SEPARATOR . 'config.footer.inc.php',
 
     /**
      * Default value for check for version upgrades.
      */
-    'versionCheckDefault' => true,
+    'versionCheckDefault' => false,
 
     /**
      * Path to files with compiled locales (*.mo)
