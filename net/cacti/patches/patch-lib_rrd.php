$NetBSD: patch-lib_rrd.php,v 1.4 2019/04/29 16:09:05 hauke Exp $

Make rrd directory configurable by package variable

--- lib/rrd.php.orig	2019-03-30 23:40:23.000000000 +0000
+++ lib/rrd.php
@@ -3425,7 +3425,7 @@ function rrdtool_parse_error($string) {
 				$rra_path = "";
 			} else {
 				if (stripos($filename, $config['base_path']) >= 0) {
-					$rra_file = str_replace($config['base_path'] . '/rra/', '', $filename);
+					$rra_file = str_replace('@CACTI_RRADIR@', '', $filename);
 					$rra_name = basename($rra_file);
 					$rra_path = dirname($rra_file);
 				} else {
