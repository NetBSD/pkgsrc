$NetBSD: patch-installer_rcube__install.php,v 1.4 2014/06/08 13:35:25 taca Exp $

Use template from examples dir.

--- installer/rcube_install.php.orig	2014-04-06 14:13:17.000000000 +0000
+++ installer/rcube_install.php
@@ -87,7 +87,7 @@ class rcube_install
   function load_config()
   {
     // defaults
-    if ($config = $this->load_config_file(RCUBE_CONFIG_DIR . 'defaults.inc.php')) {
+    if ($config = $this->load_config_file('@PKG_EXAMPLES@/' . 'defaults.inc.php')) {
         $this->config = (array) $config;
         $this->defaults = $this->config;
     }
