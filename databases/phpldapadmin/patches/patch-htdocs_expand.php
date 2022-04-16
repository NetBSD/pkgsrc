$NetBSD: patch-htdocs_expand.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- htdocs/expand.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ htdocs/expand.php
@@ -19,7 +19,7 @@ $dn = get_request('dn','GET',true);
 $tree = get_cached_item($app['server']->getIndex(),'tree');
 $entry = $tree->getEntry($dn);
 $entry->open();
-set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 
 header(sprintf('Location:index.php?server_id=%s&junk=%s#%s%s',
 	$app['server']->getIndex(),random_junk(),htmlid($app['server']->getIndex(),$dn),app_session_param()));
