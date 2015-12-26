$NetBSD: patch-config.inc.php,v 1.2 2015/12/26 14:24:48 taca Exp $

Add default paths for log, tmp and MIME types.

--- config/config.inc.php.sample	2015-03-16 20:54:49.000000000 +0000
+++ config/config.inc.php.sample.18555.sample
@@ -83,3 +83,10 @@ $config['plugins'] = array(
 
 // skin name: folder from skins/
 $config['skin'] = 'larry';
+
+// use this folder to store log files (must be writeable for apache user)
+// This is used by the 'file' log driver.
+$config['log_dir'] = '@VARBASE@/log/roundcube/';
+
+// use this folder to store temp files (must be writeable for apache user)
+$config['temp_dir'] = '@VARBASE@/tmp/roundcube/';
