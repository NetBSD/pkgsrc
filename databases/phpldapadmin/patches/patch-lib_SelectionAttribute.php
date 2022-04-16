$NetBSD: patch-lib_SelectionAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/SelectionAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/SelectionAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class SelectionAttribute extends Attribute {
+class SelectionAttribute extends PLAAttribute {
 	protected $selection = array();
 	protected $multiple;
 	protected $default;
