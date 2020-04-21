$NetBSD: patch-lib_installer.php,v 1.3 2020/04/21 13:42:52 mef Exp $

Make log directory configurable by package variable

--- lib/installer.php.orig	2019-09-30 03:36:29.000000000 +0900
+++ lib/installer.php	2020-04-21 22:17:18.590745257 +0900
@@ -465,7 +465,7 @@ class Installer implements JsonSerializa
 
 		$always_paths = array(
 			sys_get_temp_dir(),
-			$config['base_path'] . '/log',
+			'@CACTI_LOGDIR@',
 			$config['base_path'] . '/cache/boost',
 			$config['base_path'] . '/cache/mibcache',
 			$config['base_path'] . '/cache/realtime',
@@ -3226,7 +3226,7 @@ class Installer implements JsonSerializa
 		global $config;
 
 		$page_nr = 1;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
+		$logcontents = tail_file($config['base_path'] . '/cacti.log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
