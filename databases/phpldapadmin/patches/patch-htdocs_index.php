$NetBSD: patch-htdocs_index.php,v 1.1 2021/02/21 22:22:22 khorben Exp $

Bail out if the configuration file is missing

--- htdocs/index.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ htdocs/index.php
@@ -57,6 +57,11 @@ if (defined('CONFDIR'))
 else
 	$app['config_file'] = 'config.php';
 
+if (! is_readable($app['config_file'])) {
+	if (ob_get_level()) ob_end_clean();
+	die(sprintf("Missing configuration file <b>%s</b> - have you created it?",$app['config_file']));
+}
+
 # Make sure this PHP install has session support
 if (! extension_loaded('session'))
 	error('<p>Your install of PHP appears to be missing php-session support.</p><p>Please install php-session support before using phpLDAPadmin.<br /><small>(Dont forget to restart your web server afterwards)</small></p>','error',null,true);
