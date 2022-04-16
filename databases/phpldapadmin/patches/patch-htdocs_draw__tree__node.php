$NetBSD: patch-htdocs_draw__tree__node.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- htdocs/draw_tree_node.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ htdocs/draw_tree_node.php
@@ -50,7 +50,7 @@ if ($request['dn']) {
 }
 
 if ($treesave)
-	set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+	set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 
 if ($request['dn'])
 	echo $tree->draw_children($dnentry,$request['code']);
