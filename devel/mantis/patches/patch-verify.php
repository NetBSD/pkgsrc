$NetBSD: patch-verify.php,v 1.1.2.2 2017/04/17 15:52:46 bsiegert Exp $

Patch CVE-2017-7615
from http://www.mantisbt.org/blog/?p=518

--- verify.php.orig	2016-08-28 04:50:59.000000000 +0000
+++ verify.php
@@ -63,7 +63,7 @@ if( auth_is_user_authenticated() ) {
 
 $t_token_confirm_hash = token_get_value( TOKEN_ACCOUNT_ACTIVATION, $f_user_id );
 
-if( $f_confirm_hash != $t_token_confirm_hash ) {
+if( $t_token_confirm_hash == null || $f_confirm_hash !== $t_token_confirm_hash ) {
 	trigger_error( ERROR_LOST_PASSWORD_CONFIRM_HASH_INVALID, ERROR );
 }
 
