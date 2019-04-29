$NetBSD: patch-utilities.php,v 1.1 2019/04/29 16:09:05 hauke Exp $

Make log directory configurable by package variable

--- utilities.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ utilities.php
@@ -917,7 +917,7 @@ function utilities_view_logfile() {
 	}
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '@CACTI_LOGDIR@' . '/cacti.log';
 	}
 
 	if (get_nfilter_request_var('filename') != '') {
@@ -1260,7 +1260,7 @@ function utilities_clear_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = './cacti.log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
