$NetBSD: patch-lib_ObjectClassAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/ObjectClassAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/ObjectClassAttribute.php
@@ -12,6 +12,6 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class ObjectClassAttribute extends Attribute {
+class ObjectClassAttribute extends PLAAttribute {
 }
 ?>
