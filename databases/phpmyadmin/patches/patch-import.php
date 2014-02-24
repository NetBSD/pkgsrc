$NetBSD: patch-import.php,v 1.1.2.1 2014/02/24 16:31:03 schnoebe Exp $

Fix "security vulnerablity" reported in PMASA-2014-1. Patch based on
the following GIT commit:

https://github.com/phpmyadmin/phpmyadmin/commit/968d5d5f486820bfa30af046f063b9f23304e14a

--- import.php.orig	2013-12-04 17:44:44.000000000 +0000
+++ import.php	2014-02-22 11:21:37.000000000 +0000
@@ -549,9 +549,9 @@
 
             $message->addString($import_notice);
             if (isset($local_import_file)) {
-                $message->addString('(' . $local_import_file . ')');
+                $message->addString('(' . htmlspecialchars($local_import_file) . ')');
             } else {
-                $message->addString('(' . $_FILES['import_file']['name'] . ')');
+                $message->addString('(' . htmlspecialchars($_FILES['import_file']['name']) . ')');
             }
         } else {
             $message = PMA_Message::success(
@@ -559,9 +559,9 @@
             );
             $message->addParam($executed_queries);
             if (isset($local_import_file)) {
-                $message->addString('(' . $local_import_file . ')');
+                $message->addString('(' . htmlspecialchars($local_import_file) . ')');
             } else {
-                $message->addString('(' . $_FILES['import_file']['name'] . ')');
+                $message->addString('(' . htmlspecialchars($_FILES['import_file']['name']) . ')');
             }
         }
     }
