$NetBSD: patch-graph_xport.php,v 1.1 2014/08/23 12:50:25 adam Exp $

Fixes for:
CVE-2014-2326 Unspecified HTML Injection Vulnerability
CVE-2014-2328 Unspecified Remote Command Execution Vulnerability
CVE-2014-2708 Unspecified SQL Injection Vulnerability
CVE-2014-2709 Unspecified Remote Command Execution Vulnerability

--- graph_xport.php.orig	2013-08-06 22:31:19.000000000 -0400
+++ graph_xport.php		2014-04-04 21:39:04.000000000 -0400
@@ -47,43 +47,48 @@
 
 $graph_data_array = array();
 
+/* ================= input validation ================= */
+input_validate_input_number(get_request_var("local_graph_id"));
+input_validate_input_number(get_request_var("rra_id"));
+/* ==================================================== */
+
 /* override: graph start time (unix time) */
-if (!empty($_GET["graph_start"]) && $_GET["graph_start"] < 1600000000) {
-	$graph_data_array["graph_start"] = $_GET["graph_start"];
+if (!empty($_GET["graph_start"]) && is_numeric($_GET["graph_start"] && $_GET["graph_start"] < 1600000000)) {
+	$graph_data_array["graph_start"] = get_request_var("graph_start");
 }
 
 /* override: graph end time (unix time) */
-if (!empty($_GET["graph_end"]) && $_GET["graph_end"] < 1600000000) {
-	$graph_data_array["graph_end"] = $_GET["graph_end"];
+if (!empty($_GET["graph_end"]) && is_numeric($_GET["graph_end"]) && $_GET["graph_end"] < 1600000000) {
+	$graph_data_array["graph_end"] = get_request_var("graph_end");
 }
 
 /* override: graph height (in pixels) */
-if (!empty($_GET["graph_height"]) && $_GET["graph_height"] < 3000) {
-	$graph_data_array["graph_height"] = $_GET["graph_height"];
+if (!empty($_GET["graph_height"]) && is_numeric($_GET["graph_height"]) && $_GET["graph_height"] < 3000) {
+	$graph_data_array["graph_height"] = get_request_var("graph_height");
 }
 
 /* override: graph width (in pixels) */
-if (!empty($_GET["graph_width"]) && $_GET["graph_width"] < 3000) {
-	$graph_data_array["graph_width"] = $_GET["graph_width"];
+if (!empty($_GET["graph_width"]) && is_numeric($_GET["graph_width"]) && $_GET["graph_width"] < 3000) {
+	$graph_data_array["graph_width"] = get_request_var("graph_width");
 }
 
 /* override: skip drawing the legend? */
 if (!empty($_GET["graph_nolegend"])) {
-	$graph_data_array["graph_nolegend"] = $_GET["graph_nolegend"];
+	$graph_data_array["graph_nolegend"] = get_request_var("graph_nolegend");
 }
 
 /* print RRDTool graph source? */
 if (!empty($_GET["show_source"])) {
-	$graph_data_array["print_source"] = $_GET["show_source"];
+	$graph_data_array["print_source"] = get_request_var("show_source");
 }
 
-$graph_info = db_fetch_row("SELECT * FROM graph_templates_graph WHERE local_graph_id='" . $_REQUEST["local_graph_id"] . "'");
+$graph_info = db_fetch_row("SELECT * FROM graph_templates_graph WHERE local_graph_id='" . get_request_var("local_graph_id") . "'");
 
 /* for bandwidth, NThPercentile */
 $xport_meta = array();
 
 /* Get graph export */
-$xport_array = @rrdtool_function_xport($_GET["local_graph_id"], $_GET["rra_id"], $graph_data_array, $xport_meta);
+$xport_array = @rrdtool_function_xport($_GET["local_graph_id"], get_request_var("rra_id"), $graph_data_array, $xport_meta);
 
 /* Make graph title the suggested file name */
 if (is_array($xport_array["meta"])) {
