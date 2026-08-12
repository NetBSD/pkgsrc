$NetBSD: patch-init.php,v 1.1 2026/08/12 08:04:35 taca Exp $

Adjust config file's path.

--- init.php.orig	2025-03-17 23:58:10.000000000 +0000
+++ init.php
@@ -24,7 +24,7 @@ if (!defined('ROOT_PATH')) {
     define('ROOT_PATH', __DIR__ . (__DIR__ === DIRECTORY_SEPARATOR ? '' : DIRECTORY_SEPARATOR));
 }
 
-$vc = require_once(ROOT_PATH . 'config' . DIRECTORY_SEPARATOR . 'vendor_config.php');
+$vc = require_once('@PKG_SYSCONFDIR@' . DIRECTORY_SEPARATOR . 'vendor_config.php');
 if (!is_array($vc) || !isset($vc['autoload_file'], $vc['config_file'], $vc['version_suffix'])) {
     echo 'Error: Incorrect vendor config file';
     exit;
