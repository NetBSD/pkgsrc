$NetBSD: patch-lib_installer.php,v 1.1 2019/04/26 14:52:16 gavan Exp $

--- lib/installer.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ lib/installer.php
@@ -465,7 +465,7 @@ class Installer implements JsonSerializa
 
 		$always_paths = array(
 			sys_get_temp_dir(),
-			$config['base_path'] . '/log',
+			'@CACTI_LOGDIR@',
 			$config['base_path'] . '/cache/boost',
 			$config['base_path'] . '/cache/mibcache',
 			$config['base_path'] . '/cache/realtime',
