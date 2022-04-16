$NetBSD: patch-lib_PasswordAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/PasswordAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/PasswordAttribute.php
@@ -12,6 +12,6 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class PasswordAttribute extends Attribute {
+class PasswordAttribute extends PLAAttribute {
 }
 ?>
