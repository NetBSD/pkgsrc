$NetBSD: patch-lib_functions.php,v 1.3 2015/11/29 11:25:53 taca Exp $

Fix for PHP 5.5 and later: 
	https://bugzilla.redhat.com/show_bug.cgi?id=974928

--- lib/functions.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/functions.php
@@ -2127,7 +2127,7 @@ function password_types() {
  *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, sha512, or clear.
  * @return string The hashed password.
  */
-function password_hash($password_clear,$enc_type) {
+function pla_password_hash($password_clear,$enc_type) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2318,7 +2318,7 @@ function password_check($cryptedpassword
 
 		# SHA crypted passwords
 		case 'sha':
-			if (strcasecmp(password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2327,7 +2327,7 @@ function password_check($cryptedpassword
 
 		# MD5 crypted passwords
 		case 'md5':
-			if( strcasecmp(password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
+			if( strcasecmp(pla_password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2565,12 +2565,14 @@ function dn_unescape($dn) {
 		$a = array();
 
 		foreach ($dn as $key => $rdn)
-			$a[$key] = preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$rdn);
+			$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/', 
+				function ($matches) { return chr(hexdec($matches[1])); }, $rdn );
 
 		return $a;
 
 	} else {
-		return preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$dn);
+		return preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+				function ($matches) { return chr(hexdec($matches[1])); }, $dn);
 	}
 }
 
