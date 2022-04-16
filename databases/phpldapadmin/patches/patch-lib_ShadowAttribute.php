$NetBSD: patch-lib_ShadowAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/ShadowAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/ShadowAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class ShadowAttribute extends Attribute {
+class ShadowAttribute extends PLAAttribute {
 	public $shadow_before_today_attrs = array('shadowLastChange','shadowMin');
 	public $shadow_after_today_attrs = array('shadowMax','shadowExpire','shadowWarning','shadowInactive');
 }
