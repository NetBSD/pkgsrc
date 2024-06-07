$NetBSD: patch-lib_page.php,v 1.1.2.2 2024/06/07 13:52:44 bsiegert Exp $

Avoid deprecation warnings.

--- lib/page.php.orig	2024-05-08 18:12:37.313204677 +0000
+++ lib/page.php
@@ -25,6 +25,9 @@ class page {
 	# Default values array.
 	protected $_default;
 
+	# Additional properties
+	protected $index, $sysmsg, $_block;
+
 	public function __construct($index=null) {
 		if (defined('DEBUG_ENABLED') && DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',129,0,__FILE__,__LINE__,__METHOD__,$fargs);
