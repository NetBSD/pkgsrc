$NetBSD: patch-lib_TemplateRender.php,v 1.3 2024/05/08 21:32:19 khorben Exp $

Avoid deprecation warnings.

--- lib/TemplateRender.php.orig	2024-01-10 22:23:54.000000000 +0000
+++ lib/TemplateRender.php
@@ -16,6 +16,9 @@ class TemplateRender extends PageRender
 	# Page number
 	private $pagelast;
 
+	# Additional properties
+	private $layout, $url_base;
+
 	/** CORE FUNCTIONS **/
 
 	/**
