$NetBSD: patch-lib_ds__ldap.php,v 1.1 2015/11/29 11:25:53 taca Exp $

Fix for PHP 5.5 and later: 
	https://bugzilla.redhat.com/show_bug.cgi?id=974928

--- lib/ds_ldap.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/ds_ldap.php
@@ -1117,12 +1117,14 @@ class ldap extends DS {
 		if (is_array($dn)) {
 			$a = array();
 			foreach ($dn as $key => $rdn)
-				$a[$key] = preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$rdn);
+				$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+					function ($matches) { return chr(hexdec($matches[1])); }, $rdn);
 
 			return $a;
 
 		} else
-			return preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$dn);
+			return preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+					function ($matches) { return chr(hexdec($matches[1])); }, $dn);
 	}
 
 	public function getRootDSE($method=null) {
