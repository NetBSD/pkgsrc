$NetBSD: patch-lib_api_device.php,v 1.1.2.2 2014/01/09 23:14:33 spz Exp $

Fix vulnerability reported in SA54531. Patch taken from here:

http://svn.cacti.net/viewvc?view=rev&revision=7420

--- lib/api_device.php.orig	2013-08-07 03:31:18.000000000 +0100
+++ lib/api_device.php	2014-01-08 20:26:33.000000000 +0000
@@ -107,7 +107,7 @@
 		$_host_template_id = db_fetch_cell("select host_template_id from host where id=$id");
 	}
 
-	$save["id"] = $id;
+	$save["id"]                   = form_input_validate($id, "id", "^[0-9]+$", false, 3);
 	$save["host_template_id"]     = form_input_validate($host_template_id, "host_template_id", "^[0-9]+$", false, 3);
 	$save["description"]          = form_input_validate($description, "description", "", false, 3);
 	$save["hostname"]             = form_input_validate(trim($hostname), "hostname", "", false, 3);
