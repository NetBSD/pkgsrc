$NetBSD: patch-poller__maintenance.php,v 1.1 2019/04/26 14:52:16 gavan Exp $

--- poller_maintenance.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ poller_maintenance.php
@@ -439,7 +439,7 @@ function remove_files($file_array) {
 	if (isset ($config['rra_path'])) {
 		$rra_path = $config['rra_path'];
 	} else {
-		$rra_path = $config['base_path'] . '/rra';
+		$rra_path = '@CACTI_RRADIR@';
 	}
 
 	/* let's prepare the archive directory */
