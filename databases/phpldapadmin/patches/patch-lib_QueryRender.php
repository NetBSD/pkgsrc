$NetBSD: patch-lib_QueryRender.php,v 1.4 2021/02/21 22:22:22 khorben Exp $

Fix for PHP >= 7.3

--- lib/QueryRender.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/QueryRender.php
@@ -321,7 +321,7 @@ class QueryRender extends PageRender {
 					if (! $results) {
 						echo _('Search returned no results');
 
-						continue;
+						continue 2;
 					}
 
 					printf('<form action="cmd.php" method="post" id="massform_%s">',$counter);
