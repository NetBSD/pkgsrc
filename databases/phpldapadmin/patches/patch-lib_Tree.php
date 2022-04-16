$NetBSD: patch-lib_Tree.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/Tree.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/Tree.php
@@ -68,7 +68,7 @@ abstract class Tree {
 				}
 			}
 
-			set_cached_item($server_id,'tree','null',$tree);
+			set_cached_item($server_id,$tree,'tree','null');
 		}
 
 		return $tree;
