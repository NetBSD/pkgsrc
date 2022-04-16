$NetBSD: patch-lib_BinaryAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/BinaryAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/BinaryAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class BinaryAttribute extends Attribute {
+class BinaryAttribute extends PLAAttribute {
 	protected $filepaths;
 	protected $filenames;
 
