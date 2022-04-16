$NetBSD: patch-lib_GidAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/GidAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/GidAttribute.php
@@ -12,6 +12,6 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class GidAttribute extends Attribute {
+class GidAttribute extends PLAAttribute {
 }
 ?>
