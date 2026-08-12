$NetBSD: patch-config_vendor__config.php,v 1.1 2026/08/12 08:04:35 taca Exp $

Adjust config file's path.

--- config/vendor_config.php.orig	2025-03-17 23:58:10.000000000 +0000
+++ config/vendor_config.php
@@ -16,7 +16,7 @@ return [
     /**
      * Path to the configuration file.
      */
-    'config_file' => ROOT_PATH . 'config' . DIRECTORY_SEPARATOR . 'conf.php',
+    'config_file' => '@PKG_SYSCONFDIR@' . DIRECTORY_SEPARATOR . 'conf.php',
 
     /**
      * Suffix to add to the DmarcSrg version
