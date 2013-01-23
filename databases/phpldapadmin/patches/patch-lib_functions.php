$NetBSD: patch-lib_functions.php,v 1.1.2.2 2013/01/23 20:18:31 tron Exp $

* Add support for SHA512 with OpenLDAP from repository,
	21959715c3d6f204dd6c35b2e313eb2d4a01d22a.

--- lib/functions.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ lib/functions.php
@@ -1471,10 +1471,10 @@ function get_next_number($base,$attr,$in
 			for ($i=0;$i<count($autonum);$i++) {
 				$num = $autonum[$i] < $minNumber ? $minNumber : $autonum[$i];
 
-				/* If we're at the end of the list, or we've found a gap between this number and the 
-				   following, use the next available number in the gap. */ 
-				if ($i+1 == count($autonum) || $autonum[$i+1] > $num+1) 
-					return $autonum[$i] >= $num ? $num+1 : $num; 
+				/* If we're at the end of the list, or we've found a gap between this number and the
+				   following, use the next available number in the gap. */
+				if ($i+1 == count($autonum) || $autonum[$i+1] > $num+1)
+					return $autonum[$i] >= $num ? $num+1 : $num;
 			}
 
 			# If we didnt find a suitable gap and are all above the minNumber, we'll just return the $minNumber
@@ -2114,7 +2114,7 @@ function password_types() {
 		'md5crypt'=>'md5crypt',
 		'sha'=>'sha',
 		'smd5'=>'smd5',
-		'ssha'=>'ssha'
+		'ssh512'=>'ssh512'
 	);
 }
 
@@ -2123,7 +2123,7 @@ function password_types() {
  *
  * @param string The password to hash in clear text.
  * @param string Standard LDAP encryption type which must be one of
- *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, or clear.
+ *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, sha512, or clear.
  * @return string The hashed password.
  */
 function password_hash($password_clear,$enc_type) {
@@ -2216,6 +2216,16 @@ function password_hash($password_clear,$
 
 			break;
 
+		case 'sha512':
+			if (function_exists('openssl_digest') && function_exists('base64_encode')) {
+				$new_value = sprintf('{SHA512}%s', base64_encode(openssl_digest($password_clear, 'sha512', true)));
+
+			} else {
+				error(_('Your PHP install doest not have the openssl_digest() or base64_encode() function. Cannot do SHA512 hashes. '),'error','index.php');
+			}
+
+            break;
+
 		case 'clear':
 		default:
 			$new_value = $password_clear;
@@ -2379,6 +2389,15 @@ function password_check($cryptedpassword
 
 			break;
 
+			# SHA512 crypted passwords
+		case 'sha512':
+			if (strcasecmp(password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
+				return true;
+			else
+				return false;
+
+			break;
+
 		# No crypt is given assume plaintext passwords are used
 		default:
 			if ($plainpassword == $cryptedpassword)
@@ -2782,7 +2801,7 @@ function draw_formatted_dn($server,$entr
 
 	$formats = $_SESSION[APPCONFIG]->getValue('appearance','tree_display_format');
 
-	foreach ($formats as $format) { 
+	foreach ($formats as $format) {
 		$has_none = false;
 		preg_match_all('/%[a-zA-Z_0-9]+/',$format,$tokens);
 		$tokens = $tokens[0];
