$NetBSD: patch-include_global.php,v 1.2 2019/04/26 14:52:16 gavan Exp $

Make rra directory configurable by package variable

--- include/global.php.orig	2019-03-30 23:40:22.000000000 +0000
+++ include/global.php
@@ -216,7 +216,7 @@ if ($config['cacti_server_os'] == 'win32
 	$config['library_path'] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config['include_path'] = dirname(__FILE__);
-$config['rra_path'] = $config['base_path'] . '/rra';
+$config['rra_path'] = '@CACTI_RRADIR@';
 
 /* for multiple pollers, we need to know this location */
 if (!isset($scripts_path)) {
