$NetBSD: patch-htdocs_export.php,v 1.1.2.2 2013/01/23 20:18:31 tron Exp $

* Fix XSS for CVE-2012-1114/CVE-2012-1115 from repository,
	74434e5ca3fb66018fad60766f833f15689fcbfc.

--- htdocs/export.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ htdocs/export.php
@@ -29,12 +29,12 @@ if ($request['file']) {
 
 	header('Content-type: application/download');
 	header(sprintf('Content-Disposition: inline; filename="%s.%s"','export',$types['extension'].($request['export']->isCompressed() ? '.gz' : '')));
-	$request['export']->export();
+    echo $request['export']->export();
 	die();
 
 } else {
 	print '<span style="font-size: 14px; font-family: courier;"><pre>';
-	$request['export']->export();
+    echo htmlspecialchars($request['export']->export());
 	print '</pre></span>';
 }
 ?>
