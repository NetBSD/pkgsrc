$NetBSD: patch-all__db.php,v 1.1 2023/10/16 13:02:26 hauke Exp $

Replace deprecated while instruction, from
<https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=263759>

--- all_db.php.orig	2020-11-07 06:09:12.000000000 +0000
+++ all_db.php
@@ -199,7 +199,7 @@
 		echo "\t\t<td class=\"data1\">\n";
 		echo "\t\t\t<select name=\"formEncoding\">\n";
 		echo "\t\t\t\t<option value=\"\"></option>\n";
-		while (list ($key) = each ($data->codemap)) {
+		foreach ($data->codemap as $key => $value) {
 		    echo "\t\t\t\t<option value=\"", htmlspecialchars($key), "\"",
 				($key == $_POST['formEncoding']) ? ' selected="selected"' : '', ">",
 				$misc->printVal($key), "</option>\n";
