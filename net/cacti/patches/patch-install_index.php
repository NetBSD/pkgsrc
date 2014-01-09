$NetBSD: patch-install_index.php,v 1.1.1.1.18.1 2014/01/09 23:14:33 spz Exp $

- Find utilites in PREFIX first.
- Fix-up hard coded user and path (documentaion only).
- Make log directory configurable by package variable
- Fix vulnerability reported in SA54531. Patch taken from here:

  http://svn.cacti.net/viewvc?view=rev&revision=7420

--- install/index.php.orig	2013-08-07 03:31:19.000000000 +0100
+++ install/index.php	2014-01-08 20:26:33.000000000 +0000
@@ -96,7 +96,7 @@
 	if ($config["cacti_server_os"] == "win32") {
 		$search_paths = array("c:/usr/bin", "c:/cacti", "c:/rrdtool", "c:/spine", "c:/php", "c:/progra~1/php", "c:/net-snmp/bin", "c:/progra~1/net-snmp/bin", "d:/usr/bin", "d:/net-snmp/bin", "d:/progra~1/net-snmp/bin", "d:/cacti", "d:/rrdtool", "d:/spine", "d:/php", "d:/progra~1/php");
 	}else{
-		$search_paths = array("/bin", "/sbin", "/usr/bin", "/usr/sbin", "/usr/local/bin", "/usr/local/sbin");
+		$search_paths = array("@PREFIX@/bin", "@PREFIX@/sbin", "/bin", "/sbin", "/usr/bin", "/usr/sbin", "/usr/local/bin", "/usr/local/sbin");
 	}
 
 	for ($i=0; $i<count($search_paths); $i++) {
@@ -267,7 +267,7 @@
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "@CACTI_LOGDIR@" . "/cacti.log";
 }
 
 /* SNMP Version */
@@ -310,27 +310,28 @@
 }
 
 /* pre-processing that needs to be done for each step */
-if (empty($_REQUEST["step"])) {
-	$_REQUEST["step"] = 1;
-}else{
-	if ($_REQUEST["step"] == "1") {
-		$_REQUEST["step"] = "2";
-	}elseif (($_REQUEST["step"] == "2") && ($_REQUEST["install_type"] == "1")) {
-		$_REQUEST["step"] = "3";
-	}elseif (($_REQUEST["step"] == "2") && ($_REQUEST["install_type"] == "3")) {
-		$_REQUEST["step"] = "8";
-	}elseif (($_REQUEST["step"] == "8") && ($old_version_index <= array_search("0.8.5a", $cacti_versions))) {
-		$_REQUEST["step"] = "9";
-	}elseif ($_REQUEST["step"] == "8") {
-		$_REQUEST["step"] = "3";
-	}elseif ($_REQUEST["step"] == "9") {
-		$_REQUEST["step"] = "3";
-	}elseif ($_REQUEST["step"] == "3") {
-		$_REQUEST["step"] = "4";
+if (isset($_REQUEST["step"]) && $_REQUEST["step"] > 0) {
+	$step = intval($_REQUEST["step"]);
+	if ($step == "1") {
+		$step = "2";
+	} elseif (($step == "2") && ($_REQUEST["install_type"] == "1")) {
+		$step = "3";
+	} elseif (($step == "2") && ($_REQUEST["install_type"] == "3")) {
+		$step = "8";
+	} elseif (($step == "8") && ($old_version_index <= array_search("0.8.5a", $cacti_versions))) {
+		$step = "9";
+	} elseif ($step == "8") {
+		$step = "3";
+	} elseif ($step == "9") {
+		$step = "3";
+	} elseif ($step == "3") {
+		$step = "4";
 	}
+} else {
+	$step = 1;
 }
 
-if ($_REQUEST["step"] == "4") {
+if ($step == "4") {
 	include_once("../lib/data_query.php");
 	include_once("../lib/utility.php");
 
@@ -366,7 +367,7 @@
 
 	header ("Location: ../index.php");
 	exit;
-}elseif (($_REQUEST["step"] == "8") && ($_REQUEST["install_type"] == "3")) {
+}elseif (($step == "8") && ($_REQUEST["install_type"] == "3")) {
 	/* if the version is not found, die */
 	if (!is_int($old_version_index)) {
 		print "	<p style='font-family: Verdana, Arial; font-size: 16px; font-weight: bold; color: red;'>Error</p>
@@ -505,7 +506,7 @@
 				</tr>
 				<tr>
 					<td width="100%" style="font-size: 12px;">
-						<?php if ($_REQUEST["step"] == "1") { ?>
+						<?php if ($step == "1") { ?>
 
 						<p>Thanks for taking the time to download and install cacti, the complete graphing
 						solution for your network. Before you can start making cool graphs, there are a few
@@ -530,7 +531,7 @@
 						MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 						GNU General Public License for more details.</p>
 
-						<?php }elseif ($_REQUEST["step"] == "2") { ?>
+						<?php }elseif ($step == "2") { ?>
 
 						<p>Please select the type of installation</p>
 
@@ -551,7 +552,7 @@
 							print "Server Operating System Type: " . $config["cacti_server_os"] . "<br>"; ?>
 						</p>
 
-						<?php }elseif ($_REQUEST["step"] == "3") { ?>
+						<?php }elseif ($step == "3") { ?>
 
 						<p>Make sure all of these values are correct before continuing.</p>
 						<?php
@@ -609,7 +610,7 @@
 						is an upgrade. You can change any of the settings on this screen at a later
 						time by going to "Cacti Settings" from within Cacti.</p>
 
-						<?php }elseif ($_REQUEST["step"] == "8") { ?>
+						<?php }elseif ($step == "8") { ?>
 
 						<p>Upgrade results:</p>
 
@@ -659,7 +660,7 @@
 						print $upgrade_results;
 						?>
 
-						<?php }elseif ($_REQUEST["step"] == "9") { ?>
+						<?php }elseif ($step == "9") { ?>
 
 						<p style='font-size: 16px; font-weight: bold; color: red;'>Important Upgrade Notice</p>
 
@@ -667,13 +668,13 @@
 
 						<p>See the sample crontab entry below with the change made in red. Your crontab line will look slightly different based upon your setup.</p>
 
-						<p><tt>*/5 * * * * cactiuser php /var/www/html/cacti/<span style='font-weight: bold; color: red;'>poller.php</span> &gt; /dev/null 2&gt;&amp;1</tt></p>
+						<p><tt>*/5 * * * * @CACTI_USER@ php @CACTIDIR@<span style='font-weight: bold; color: red;'>poller.php</span> &gt; /dev/null 2&gt;&amp;1</tt></p>
 
 						<p>Once you have made this change, please click Next to continue.</p>
 
 						<?php }?>
 
-						<p align="right"><input type="image" src="install_<?php if ($_REQUEST["step"] == "3") {?>finish<?php }else{?>next<?php }?>.gif" alt="<?php if ($_REQUEST["step"] == "3"){?>Finish<?php }else{?>Next<?php }?>"></p>
+						<p align="right"><input type="image" src="install_<?php if ($step == "3") {?>finish<?php }else{?>next<?php }?>.gif" alt="<?php if ($step == "3"){?>Finish<?php }else{?>Next<?php }?>"></p>
 					</td>
 				</tr>
 			</table>
@@ -681,7 +682,7 @@
 	</tr>
 </table>
 
-<input type="hidden" name="step" value="<?php print $_REQUEST["step"];?>">
+<input type="hidden" name="step" value="<?php print $step;?>">
 
 </form>
 
