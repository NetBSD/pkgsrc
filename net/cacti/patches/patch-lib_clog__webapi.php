$NetBSD: patch-lib_clog__webapi.php,v 1.1 2019/04/29 16:09:05 hauke Exp $

Make log directory configurable by package variable

--- lib/clog_webapi.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ lib/clog_webapi.php
@@ -56,7 +56,7 @@ function clog_validate_filename(&$file, 
 	$logbase = basename($logfile);
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '@CACTI_LOGDIR@' . '/cacti.log';
 	}
 
 	$errfile = read_config_option('path_stderrlog');
