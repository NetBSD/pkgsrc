$NetBSD: patch-lib_MultiLineAttribute.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/MultiLineAttribute.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/MultiLineAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class MultiLineAttribute extends Attribute {
+class MultiLineAttribute extends PLAAttribute {
 	protected $rows = 0;
 	protected $cols = 0;
 
