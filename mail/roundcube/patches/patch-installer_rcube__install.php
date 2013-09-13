$NetBSD: patch-installer_rcube__install.php,v 1.3 2013/09/13 11:13:49 taca Exp $

Use template from examples dir.

--- installer/rcube_install.php.orig	2013-09-06 12:20:52.000000000 +0000
+++ installer/rcube_install.php
@@ -147,7 +147,7 @@ class rcube_install
    */
   function create_config($which, $force = false)
   {
-    $out = @file_get_contents(RCUBE_CONFIG_DIR . $which . '.inc.php.dist');
+    $out = @file_get_contents('@PKG_EXAMPLES@/' . $which . '.inc.php.dist');
 
     if (!$out)
       return '[Warning: could not read the config template file]';
