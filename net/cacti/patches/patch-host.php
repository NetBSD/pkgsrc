$NetBSD: patch-host.php,v 1.1.2.2 2014/01/09 23:14:33 spz Exp $

Fix vulnerability reported in SA54531. Patch taken from here:

http://svn.cacti.net/viewvc?view=rev&revision=7420

--- host.php.orig	2013-08-07 03:31:19.000000000 +0100
+++ host.php	2014-01-08 20:26:33.000000000 +0000
@@ -149,6 +149,9 @@
 		if ($_POST["snmp_version"] == 3 && ($_POST["snmp_password"] != $_POST["snmp_password_confirm"])) {
 			raise_message(4);
 		}else{
+			input_validate_input_number(get_request_var_post("id"));
+			input_validate_input_number(get_request_var_post("host_template_id"));
+
 			$host_id = api_device_save($_POST["id"], $_POST["host_template_id"], $_POST["description"],
 				trim($_POST["hostname"]), $_POST["snmp_community"], $_POST["snmp_version"],
 				$_POST["snmp_username"], $_POST["snmp_password"],
