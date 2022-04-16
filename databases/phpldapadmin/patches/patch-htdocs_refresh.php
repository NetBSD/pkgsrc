$NetBSD: patch-htdocs_refresh.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- htdocs/refresh.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ htdocs/refresh.php
@@ -34,7 +34,7 @@ if (get_request('purge','REQUEST')) {
 		$entry->open();
 	}
 
-	set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+	set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 }
 
 if (get_request('meth','REQUEST') == 'ajax') 
