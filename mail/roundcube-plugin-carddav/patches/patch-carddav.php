$NetBSD: patch-carddav.php,v 1.3 2022/07/11 09:59:06 triaxx Exp $

* Make pkgsrc-compliant the path of configuration file.

--- carddav.php.orig	2021-03-20 16:59:43.000000000 +0000
+++ carddav.php
@@ -1274,7 +1274,7 @@ class carddav extends rcube_plugin
         $logger = Config::inst()->logger();
         $httpLogger = Config::inst()->httpLogger();
         $prefs = [];
-        $configfile = dirname(__FILE__) . "/config.inc.php";
+        $configfile = "@PKG_SYSCONFDIR@/config.inc.php";
         if (file_exists($configfile)) {
             include($configfile);
         }
