$NetBSD: patch-lib_xmlTemplates.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/xmlTemplates.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/xmlTemplates.php
@@ -140,7 +140,7 @@ abstract class xmlTemplates {
 
 		if ($changed) {
 			masort($this->templates,'title');
-			set_cached_item($server_id,$class['item'],'null',$this->templates);
+			set_cached_item($server_id,$this->templates,$class['item'],'null');
 		}
 	}
 
