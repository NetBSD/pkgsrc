$NetBSD: patch-lib_ds__ldap__pla.php,v 1.1 2021/02/21 22:22:22 khorben Exp $

Fix for PHP >= 5.5

--- lib/ds_ldap_pla.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/ds_ldap_pla.php
@@ -16,7 +16,7 @@ class ldap_pla extends ldap {
 	function __construct($index) {
 		parent::__construct($index);
 
-		$this->default->appearance['password_hash'] = array(
+		$this->default->appearance['pla_password_hash'] = array(
 			'desc'=>'Default HASH to use for passwords',
 			'default'=>'md5');
 
