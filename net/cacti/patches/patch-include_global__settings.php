$NetBSD: patch-include_global__settings.php,v 1.2 2019/04/26 14:52:16 gavan Exp $

make log directory configurable by package variable

--- include/global_settings.php.orig	2019-03-30 23:40:22.000000000 +0000
+++ include/global_settings.php
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
