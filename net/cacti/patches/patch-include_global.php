$NetBSD: patch-include_global.php,v 1.1.1.1 2011/11/22 22:23:13 tez Exp $

Make rra directory configurable by package variable

--- include/global.php.orig	2011-09-26 20:41:03.000000000 +0000
+++ include/global.php
@@ -103,7 +103,7 @@ if ($config["cacti_server_os"] == "win32
 	$config["library_path"] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config["include_path"] = dirname(__FILE__);
-$config["rra_path"] = $config["base_path"] . '/rra';
+$config["rra_path"] = '@CACTI_RRADIR@';
 
 /* colors */
 $colors["dark_outline"] = "454E53";
