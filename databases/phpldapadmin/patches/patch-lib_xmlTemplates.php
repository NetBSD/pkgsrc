$NetBSD: patch-lib_xmlTemplates.php,v 1.2 2024/05/08 21:32:20 khorben Exp $

Avoid deprecation warnings.

--- lib/xmlTemplates.php.orig	2024-01-10 22:23:54.000000000 +0000
+++ lib/xmlTemplates.php
@@ -272,6 +272,9 @@ abstract class xmlTemplate {
 	# The TEMPLATE attributes as per the template definition, or the DN entry
 	protected $attributes = array();
 
+	# Additional properties
+	protected $askcontainer;
+
 	public function __construct($server_id,$name='',$filename=null,$type=null,$id=null) {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs);
