$NetBSD: patch-include_global__settings.php,v 1.1.1.1 2011/11/22 22:23:13 tez Exp $

make log directory configurable by package variable

--- include/global_settings.php.orig	2011-09-26 20:41:03.000000000 +0000
+++ include/global_settings.php
@@ -96,9 +96,9 @@ $settings = array(
 			),
 		"path_cactilog" => array(
 			"friendly_name" => "Cacti Log File Path",
-			"description" => "The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)",
+			"description" => "The path to your Cacti log file (if blank, defaults to @CACTI_LOGDIR@/cacti.log)",
 			"method" => "filepath",
-			"default" => $config["base_path"] . "/log/cacti.log",
+			"default" => "@CACTI_LOGDIR@" . "/cacti.log",
 			"max_length" => "255"
 			),
 		"pollerpaths_header" => array(
