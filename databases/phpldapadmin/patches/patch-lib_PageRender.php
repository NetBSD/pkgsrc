$NetBSD: patch-lib_PageRender.php,v 1.1 2021/02/21 22:22:22 khorben Exp $

Fix for PHP >= 5.5

--- lib/PageRender.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/PageRender.php
@@ -287,7 +287,7 @@ class PageRender extends Visitor {
 						break;
 
 					default:
-						$vals[$i] = password_hash($passwordvalue,$enc);
+						$vals[$i] = pla_password_hash($passwordvalue,$enc);
 				}
 
 				$vals = array_unique($vals);
@@ -957,7 +957,7 @@ class PageRender extends Visitor {
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','pla_password_hash');
 
 		$obfuscate_password = obfuscate_password_display($enc_type);
 
@@ -982,7 +982,7 @@ class PageRender extends Visitor {
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','pla_password_hash');
 
 		echo '<table cellspacing="0" cellpadding="0"><tr><td valign="top">';
 
