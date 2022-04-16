$NetBSD: patch-lib_AttributeFactory.php,v 1.1 2022/04/16 03:11:28 khorben Exp $

--- lib/AttributeFactory.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/AttributeFactory.php
@@ -133,7 +133,7 @@ class AttributeFactory {
 			return $this->newGidAttribute($name,$values,$server_id,$source);
 
 		} else {
-			return new Attribute($name,$values,$server_id,$source);
+			return new PLAAttribute($name,$values,$server_id,$source);
 		}
 	}
 
