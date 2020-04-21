$NetBSD: patch-include_global__settings.php,v 1.4 2020/04/21 13:42:52 mef Exp $

make log and rrd directories configurable by package variable

--- include/global_settings.php.orig	2019-09-30 03:36:27.000000000 +0900
+++ include/global_settings.php	2020-04-21 22:18:08.198340988 +0900
@@ -160,7 +160,7 @@ $settings = array(
 			),
 		'path_cactilog' => array(
 			'friendly_name' => __('Cacti Log Path'),
-			'description' => __('The path to your Cacti log file (if blank, defaults to &lt;path_cacti&gt;/log/cacti.log)'),
+			'description' => __('The path to your Cacti log file (if blank, defaults to @CACTI_LOGDIR@/cacti.log)'),
 			'method' => 'filepath',
 			'file_type' => 'ascii',
 			'default' => $config['base_path'] . '/log/cacti.log',
@@ -172,7 +172,7 @@ $settings = array(
 			'description' => __('If you are having issues with Cacti\'s Data Collectors, set this file path and the Data Collectors standard error will be redirected to this file'),
 			'method' => 'filepath',
 			'file_type' => 'ascii',
-			'default' => $config['base_path'] . '/log/cacti_stderr.log',
+			'default' => '@CACTI_LOGDIR@' . '/cacti_stderr.log',
 			'max_length' => '255',
 			'install_check' => 'writable',
 			'install_optional' => true
@@ -243,7 +243,7 @@ $settings = array(
 			'friendly_name' => __('Archive directory'),
 			'description' => __('This is the directory where RRDfiles are <strong>moved</strong> for archiving'),
 			'method' => 'dirpath',
-			'default' => $config['base_path'] . '/rra/archive/',
+			'default' => '@CACTI_RRADIR' . '/archive/',
 			'max_length' => 255,
 			),
 		),
@@ -1782,7 +1782,7 @@ $settings = array(
 			),
 		'extended_paths' => array(
 			'friendly_name' => __('Structured RRD Paths'),
-			'description' => __('Use a separate subfolder for each hosts RRD files.  The naming of the RRDfiles will be &lt;path_cacti&gt;/rra/host_id/local_data_id.rrd.'),
+			'description' => __('Use a separate subfolder for each hosts RRD files.  The naming of the RRDfiles will be @CACTI_RRADIR@/host_id/local_data_id.rrd.'),
 			'method' => 'checkbox'
 			),
 		'rrdp_header' => array(
