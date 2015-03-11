$NetBSD: patch-install_index.php,v 1.3 2015/03/11 13:56:46 adam Exp $

- Find utilites in PREFIX first.
- Fix-up hard coded user and path (documentaion only).
- Make log directory configurable by package variable

--- install/index.php.orig	2014-11-23 20:18:57.000000000 +0000
+++ install/index.php
@@ -96,7 +96,7 @@ function find_best_path($binary_name) {
 	if ($config["cacti_server_os"] == "win32") {
 		$search_paths = array("c:/usr/bin", "c:/cacti", "c:/rrdtool", "c:/spine", "c:/php", "c:/progra~1/php", "c:/net-snmp/bin", "c:/progra~1/net-snmp/bin", "d:/usr/bin", "d:/net-snmp/bin", "d:/progra~1/net-snmp/bin", "d:/cacti", "d:/rrdtool", "d:/spine", "d:/php", "d:/progra~1/php");
 	}else{
-		$search_paths = array("/bin", "/sbin", "/usr/bin", "/usr/sbin", "/usr/local/bin", "/usr/local/sbin");
+		$search_paths = array("@PREFIX@/bin", "@PREFIX@/sbin", "/bin", "/sbin", "/usr/bin", "/usr/sbin", "/usr/local/bin", "/usr/local/sbin");
 	}
 
 	for ($i=0; $i<count($search_paths); $i++) {
@@ -267,7 +267,7 @@ $input["path_cactilog"]["description"] =
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "@CACTI_LOGDIR@" . "/cacti.log";
 }
 
 /* SNMP Version */
@@ -670,7 +670,7 @@ if ($step == "4") {
 
 						<p>See the sample crontab entry below with the change made in red. Your crontab line will look slightly different based upon your setup.</p>
 
-						<p><tt>*/5 * * * * cactiuser php /var/www/html/cacti/<span style='font-weight: bold; color: red;'>poller.php</span> &gt; /dev/null 2&gt;&amp;1</tt></p>
+						<p><tt>*/5 * * * * @CACTI_USER@ php @CACTIDIR@<span style='font-weight: bold; color: red;'>poller.php</span> &gt; /dev/null 2&gt;&amp;1</tt></p>
 
 						<p>Once you have made this change, please click Next to continue.</p>
 
