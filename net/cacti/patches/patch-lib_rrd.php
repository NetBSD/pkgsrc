$NetBSD: patch-lib_rrd.php,v 1.1 2014/08/23 12:50:25 adam Exp $

Fixes for:
CVE-2014-2326 Unspecified HTML Injection Vulnerability
CVE-2014-2328 Unspecified Remote Command Execution Vulnerability
CVE-2014-2708 Unspecified SQL Injection Vulnerability
CVE-2014-2709 Unspecified Remote Command Execution Vulnerability

--- lib/rrd.php.orig	2013-08-06 22:31:18.000000000 -0400
+++ lib/rrd.php		2014-04-04 21:39:04.000000000 -0400
@@ -865,13 +865,13 @@
 	/* basic graph options */
 	$graph_opts .=
 		"--imgformat=" . $image_types{$graph["image_format_id"]} . RRD_NL .
-		"--start=$graph_start" . RRD_NL .
-		"--end=$graph_end" . RRD_NL .
+		"--start=" . cacti_escapeshellarg($graph_start) . RRD_NL .
+		"--end=" . cacti_escapeshellarg($graph_end) . RRD_NL .
 		"--title=" . cacti_escapeshellarg($graph["title_cache"]) . RRD_NL .
 		"$rigid" .
-		"--base=" . $graph["base_value"] . RRD_NL .
-		"--height=$graph_height" . RRD_NL .
-		"--width=$graph_width" . RRD_NL .
+		"--base=" . cacti_escapeshellarg($graph["base_value"]) . RRD_NL .
+		"--height=" . cacti_escapeshellarg($graph_height) . RRD_NL .
+		"--width=" . cacti_escapeshellarg($graph_width) . RRD_NL .
 		"$scale" .
 		"$unit_value" .
 		"$unit_exponent_value" .
@@ -1606,8 +1606,8 @@
 
 	/* basic export options */
 	$xport_opts =
-		"--start=$xport_start" . RRD_NL .
-		"--end=$xport_end" . RRD_NL .
+		"--start=" . cacti_escapeshellarg($xport_start) . RRD_NL .
+		"--end=" . cacti_escapeshellarg($xport_end) . RRD_NL .
 		"--maxrows=10000" . RRD_NL;
 
 	$xport_defs = "";
@@ -1997,7 +1997,7 @@
 			$stacked_columns["col" . $j] = ($graph_item_types{$xport_item["graph_type_id"]} == "STACK") ? 1 : 0;
 			$j++;
 
-			$txt_xport_items .= "XPORT:" . $data_source_name . ":" . str_replace(":", "", cacti_escapeshellarg($legend_name)) ;
+			$txt_xport_items .= "XPORT:" . cacti_escapeshellarg($data_source_name) . ":" . str_replace(":", "", cacti_escapeshellarg($legend_name)) ;
 		}else{
 			$need_rrd_nl = FALSE;
 		}
