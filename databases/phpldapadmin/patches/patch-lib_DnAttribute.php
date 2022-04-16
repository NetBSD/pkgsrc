$NetBSD: patch-lib_DnAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/DnAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/DnAttribute.php
@@ -12,6 +12,6 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class DnAttribute extends Attribute {
+class DnAttribute extends PLAAttribute {
 }
 ?>
