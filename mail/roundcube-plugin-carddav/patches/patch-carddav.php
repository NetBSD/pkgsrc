$NetBSD: patch-carddav.php,v 1.2 2021/05/18 07:13:26 triaxx Exp $

* Make pkgsrc-compliant the path of configuration file.

--- carddav.php.orig	2021-03-20 16:59:43.000000000 +0000
+++ carddav.php
@@ -1158,7 +1158,7 @@ class carddav extends rcube_plugin
         $logger = Config::inst()->logger();
         $httpLogger = Config::inst()->httpLogger();
         $prefs = [];
-        $configfile = dirname(__FILE__) . "/config.inc.php";
+        $configfile = "@PKG_SYSCONFDIR@/config.inc.php";
         if (file_exists($configfile)) {
             include($configfile);
         }
