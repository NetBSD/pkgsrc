$NetBSD: patch-install_functions.php,v 1.1 2019/04/29 16:09:05 hauke Exp $

Find utilites in PREFIX first.
Make log directory configurable by package variable

--- install/functions.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ install/functions.php
@@ -298,8 +298,8 @@ function find_best_path($binary_name) {
 		);
 	} else {
 		$search_paths = array(
-			'/bin',
-			'/sbin',
+			'@PREFIX@/bin',
+			'@PREFIX@/sbin',
 			'/usr/bin',
 			'/usr/sbin',
 			'/usr/local/bin',
@@ -475,42 +475,42 @@ function install_file_paths() {
 	/* RRDtool Binary Path */
 	$input['path_rrdtool'] = install_tool_path('rrdtool',
 		array(
-			'unix'  => '/usr/local/bin/rrdtool',
+			'unix'  => '@PREFIX@/bin/rrdtool',
 			'win32' => 'c:/rrdtool/rrdtool.exe'
 		));
 
 	/* snmpwalk Binary Path */
 	$input['path_snmpwalk'] = install_tool_path('snmpwalk',
 		array(
-			'unix'  => '/usr/local/bin/snmpwalk',
+			'unix'  => '@PREFIX@/bin/snmpwalk',
 			'win32' => 'c:/net-snmp/bin/snmpwalk.exe'
 		));
 
 	/* snmpget Binary Path */
 	$input['path_snmpget'] = install_tool_path('snmpget',
 		array(
-			'unix'  => '/usr/local/bin/snmpget',
+			'unix'  => '@PREFIX@/bin/snmpget',
 			'win32' => 'c:/net-snmp/bin/snmpget.exe'
 		));
 
 	/* snmpbulkwalk Binary Path */
 	$input['path_snmpbulkwalk'] = install_tool_path('snmpbulkwalk',
 		array(
-			'unix'  => '/usr/local/bin/snmpbulkwalk',
+			'unix'  => '@PREFIX@/bin/snmpbulkwalk',
 			'win32' => 'c:/net-snmp/bin/snmpbulkwalk.exe'
 		));
 
 	/* snmpgetnext Binary Path */
 	$input['path_snmpgetnext'] = install_tool_path('snmpgetnext',
 		array(
-			'unix'  => '/usr/local/bin/snmpgetnext',
+			'unix'  => '@PREFIX@/bin/snmpgetnext',
 			'win32' => 'c:/net-snmp/bin/snmpgetnext.exe'
 		));
 
 	/* snmptrap Binary Path */
 	$input['path_snmptrap'] = install_tool_path('snmptrap',
 		array(
-			'unix'  => '/usr/local/bin/snmptrap',
+			'unix'  => '@PREFIX@/bin/snmptrap',
 			'win32' => 'c:/net-snmp/bin/snmptrap.exe'
 		));
 
@@ -523,7 +523,7 @@ function install_file_paths() {
 	/* spine Binary Path */
 	$input['path_spine'] = install_tool_path('spine',
 		array(
-			'unix'  => '/usr/local/spine/bin/spine',
+			'unix'  => '@PREFIX@/bin/spine',
 			'win32' => 'c:/spine/bin/spine.exe'
 		));
 
@@ -533,7 +533,7 @@ function install_file_paths() {
 	if (!config_value_exists('path_cactilog')) {
 		$input['path_cactilog'] = $settings['path']['path_cactilog'];
 		if (empty($input['path_cactilog']['default'])) {
-			$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+			$input['path_cactilog']['default'] = '@CACTI_LOGDIR@' . '/cacti.log';
 		}
 	} else {
 		$input['path_cactilog'] = $settings['path']['path_cactilog'];
@@ -544,7 +544,7 @@ function install_file_paths() {
 	if (!config_value_exists('path_cactilog')) {
 		$input['path_stderrlog'] = $settings['path']['path_stderrlog'];
 		if (empty($input['path_stderrlog']['default'])) {
-			$input['path_stderrlog']['default'] = $config['base_path'] . '/log/cacti.stderr.log';
+			$input['path_stderrlog']['default'] = '@CACTI_LOGDIR@' . '/cacti.stderr.log';
 		}
 	} else {
 		$input['path_stderrlog'] = $settings['path']['path_stderrlog'];
@@ -802,7 +802,7 @@ function log_install_to_file($section, $
 			$section = 'general';
 		}
 		$logfile = 'install' . '-' . $section;
-		file_put_contents($config['base_path'] . '/log/' . $logfile . '.log', sprintf($format_log1, $day, $time, $levelname, $data, PHP_EOL), $flags);
-		file_put_contents($config['base_path'] . '/log/install-complete.log', sprintf($format_log2, $day, $time, $sectionname, $levelname, $data, PHP_EOL), $flags);
+		file_put_contents('@CACTI_LOGDIR@' . '/' . $logfile . '.log', sprintf($format_log1, $day, $time, $levelname, $data, PHP_EOL), $flags);
+		file_put_contents('@CACTI_LOGDIR@' . '/install-complete.log', sprintf($format_log2, $day, $time, $sectionname, $levelname, $data, PHP_EOL), $flags);
 	}
 }
