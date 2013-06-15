$NetBSD: patch-program_include_rcmail.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit acb4b71ce55f3d98f7053b7bb8fdcf3c7858fbfc:
  Fix error when there's no writeable addressbook source (#1489162) 

--- program/include/rcmail.php.orig	2013-05-16 18:06:35.000000000 +0000
+++ program/include/rcmail.php
@@ -228,6 +228,11 @@ class rcmail extends rcube
     }
 
     if (!$contacts) {
+      // there's no default, just return
+      if ($default) {
+        return null;
+      }
+
       self::raise_error(array(
         'code' => 700, 'type' => 'php',
         'file' => __FILE__, 'line' => __LINE__,
