$NetBSD: patch-lib_ds__ldap.php,v 1.2 2022/04/16 03:11:28 khorben Exp $

Fix for PHP 5.5 and later: 
	https://bugzilla.redhat.com/show_bug.cgi?id=974928

--- lib/ds_ldap.php.orig	2022-04-15 22:45:43.000000000 +0000
+++ lib/ds_ldap.php
@@ -1768,7 +1768,7 @@ class ldap extends DS {
 			ksort($return);
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','objectclasses',$return);
+			set_cached_item($this->index,$return,'schema','objectclasses');
 		}
 
 		if (DEBUG_ENABLED)
@@ -1953,7 +1953,7 @@ class ldap extends DS {
 			$return = $attrs;
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','attributes',$return);
+			set_cached_item($this->index,$return,'schema','attributes');
 		}
 
 		if (DEBUG_ENABLED)
@@ -2029,7 +2029,7 @@ class ldap extends DS {
 			$return = $rules;
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','matchingrules',$return);
+			set_cached_item($this->index,$return,'schema','matchingrules');
 		}
 
 		if (DEBUG_ENABLED)
@@ -2078,7 +2078,7 @@ class ldap extends DS {
 			ksort($return);
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','syntaxes',$return);
+			set_cached_item($this->index,$return,'schema','syntaxes');
 		}
 
 		if (DEBUG_ENABLED)
