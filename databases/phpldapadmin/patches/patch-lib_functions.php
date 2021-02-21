$NetBSD: patch-lib_functions.php,v 1.4 2021/02/21 22:22:22 khorben Exp $

Fix for PHP 5.5 and later: 
	https://bugzilla.redhat.com/show_bug.cgi?id=974928

--- lib/functions.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/functions.php
@@ -51,7 +51,7 @@ if (file_exists(LIBDIR.'functions.custom
 /**
  * Loads class definition
  */
-function __autoload($className) {
+function pla_autoload($className) {
 	if (file_exists(HOOKSDIR."classes/$className.php"))
 		require_once(HOOKSDIR."classes/$className.php");
 	elseif (file_exists(LIBDIR."$className.php"))
@@ -66,6 +66,12 @@ function __autoload($className) {
 			'type'=>'error'));
 }
 
+if (version_compare(phpversion(), '7.0', '>=')) {
+	spl_autoload_register('pla_autoload');
+} else {
+	eval('function __autoload($className) {pla_autoload($className);}');
+}
+
 /**
  * Strips all slashes from the specified array in place (pass by ref).
  * @param Array The array to strip slashes from, typically one of
@@ -994,6 +1000,22 @@ function get_custom_file($index,$filenam
 }
 
 /**
+ * Replacement for create_function() which is deprecated as of PHP 7.2
+ *
+ * @param string The function arguments
+ * @param string The function code
+ */
+function pla_create_function($args, $code) {
+	if (version_compare(phpversion(), '7.0', '>=')) {
+		# anonymous functions were introduced in PHP 5.3.0
+		return eval("return function(".$args."){".$code."};");
+	} else {
+		# create_function is deprecated in PHP 7.2
+		return create_function($args, $code);
+	}
+}
+
+/**
  * Sort a multi dimensional array.
  *
  * @param array Multi demension array passed by reference
@@ -1080,7 +1102,7 @@ function masort(&$data,$sortby,$rev=0) {
 
 		$code .= 'return $c;';
 
-		$CACHE[$sortby] = create_function('$a, $b',$code);
+		$CACHE[$sortby] = pla_create_function('$a, $b',$code);
 	}
 
 	uasort($data,$CACHE[$sortby]);
@@ -2127,7 +2149,7 @@ function password_types() {
  *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, sha512, or clear.
  * @return string The hashed password.
  */
-function password_hash($password_clear,$enc_type) {
+function pla_password_hash($password_clear,$enc_type) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2318,7 +2340,7 @@ function password_check($cryptedpassword
 
 		# SHA crypted passwords
 		case 'sha':
-			if (strcasecmp(password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2327,7 +2349,7 @@ function password_check($cryptedpassword
 
 		# MD5 crypted passwords
 		case 'md5':
-			if( strcasecmp(password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
+			if( strcasecmp(pla_password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2392,7 +2414,7 @@ function password_check($cryptedpassword
 
 		# SHA512 crypted passwords
 		case 'sha512':
-			if (strcasecmp(password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2565,12 +2587,14 @@ function dn_unescape($dn) {
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
 
