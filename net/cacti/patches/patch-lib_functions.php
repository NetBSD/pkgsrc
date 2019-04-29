$NetBSD: patch-lib_functions.php,v 1.1 2019/04/29 16:09:05 hauke Exp $

Make log directory configurable by package variable

--- lib/functions.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ lib/functions.php
@@ -832,7 +832,7 @@ function cacti_log_file() {
 	global $config;
 	$logfile        = read_config_option('path_cactilog');
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '@CACTI_LOGDIR@' . '/cacti.log';
 	}
 	$config['log_path'] = $logfile;
 	return $logfile;
