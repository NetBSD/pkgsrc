$NetBSD: patch-lib_installer.php,v 1.2 2019/04/29 16:09:05 hauke Exp $

Make log directory configurable by package variable

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
@@ -3184,7 +3184,7 @@ class Installer implements JsonSerializa
 
 	public static function getInstallLog() {
 		global $config;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , 1, $total_rows);
+		$logcontents = tail_file('@CACTI_LOGDIR@' . '/cacti.log', 100, -1, ' INSTALL:' , 1, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
