$NetBSD: patch-lib_schema__functions.php,v 1.1 2024/05/08 21:32:20 khorben Exp $

Avoid deprecation warnings.

--- lib/schema_functions.php.orig	2024-01-10 22:23:54.000000000 +0000
+++ lib/schema_functions.php
@@ -24,7 +24,7 @@ abstract class SchemaItem {
 	# The description of this schema item.
 	protected $description = '';
 	# Boolean value indicating whether this objectClass is obsolete
-	private $is_obsolete = false;
+	protected $is_obsolete = false;
 
 	public function setOID($oid) {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
