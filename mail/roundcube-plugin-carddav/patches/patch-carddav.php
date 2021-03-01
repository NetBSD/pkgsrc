$NetBSD: patch-carddav.php,v 1.1 2021/03/01 12:42:26 triaxx Exp $

* Make pkgsrc-compliant the path of configuration file.

--- carddav.php.orig	2020-11-29 16:41:48.000000000 +0000
+++ carddav.php
@@ -1043,7 +1043,7 @@ class carddav extends rcube_plugin
         }
 
         $prefs = [];
-        $configfile = dirname(__FILE__) . "/config.inc.php";
+        $configfile = "@PKG_SYSCONFDIR@/config.inc.php";
         if (file_exists($configfile)) {
             include($configfile);
         }
