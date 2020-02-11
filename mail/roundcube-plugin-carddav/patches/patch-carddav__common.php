$NetBSD: patch-carddav__common.php,v 1.1 2020/02/11 20:36:49 triaxx Exp $

* Fix issue with large CardDAV collection (Github #259).
* Make pkgsrc-compliant the path of configuration file.

--- carddav_common.php.orig	2018-10-01 07:23:22.000000000 +0000
+++ carddav_common.php
@@ -114,7 +114,7 @@ class carddav_common
 		if(!self::check_contenttype($reply['headers']['content-type'], ';(text|application)/xml;'))
 			return false;
 
-		$xml = new SimpleXMLElement($reply['body']);
+    $xml = simplexml_load_string($reply['body'], 'SimpleXMLElement', LIBXML_COMPACT | LIBXML_PARSEHUGE);
 		$this->registerNamespaces($xml);
 		return $xml;
 	}
@@ -373,7 +373,7 @@ class carddav_common
 
 	$rcmail = rcmail::get_instance();
 	$prefs = array();
-	$configfile = dirname(__FILE__)."/config.inc.php";
+	$configfile = "@PKG_SYSCONFDIR@/config.inc.php";
 	if (file_exists($configfile)){
 		require("$configfile");
 	}
