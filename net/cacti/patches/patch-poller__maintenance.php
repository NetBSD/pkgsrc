$NetBSD: patch-poller__maintenance.php,v 1.2 2019/04/29 16:09:05 hauke Exp $

Make rrd directory configurable by package variable

--- poller_maintenance.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ poller_maintenance.php
@@ -227,7 +227,7 @@ function logrotate_rotatenow() {
 	$logs = array();
 	$log = read_config_option('path_cactilog');
 	if (empty($log)) {
-		$log = $config['base_path'] . '/log/cacti.log';
+		$log = '@CACTI_LOGDIR@' . '/cacti.log';
 	}
 	$logs['Cacti'] = $log;
 
@@ -439,7 +439,7 @@ function remove_files($file_array) {
 	if (isset ($config['rra_path'])) {
 		$rra_path = $config['rra_path'];
 	} else {
-		$rra_path = $config['base_path'] . '/rra';
+		$rra_path = '@CACTI_RRADIR@';
 	}
 
 	/* let's prepare the archive directory */
