$NetBSD: patch-plugins_gpg_gpg_decrypt_attach.php,v 1.1 2016/09/27 12:11:11 manu Exp $

PHP 5 compatibility fix, from Jean-Jacques Puig.

--- plugins/gpg/gpg_decrypt_attach.php.orig
+++ plugins/gpg/gpg_decrypt_attach.php
@@ -181,15 +181,17 @@
         return $return;
 }
 
-function scandir($dirstr) {
-    // php.net/scandir (PHP5)
-    $files = array();
-    $fh = opendir($dirstr);
-    while (false !== ($filename = readdir($fh))) {
-        array_push($files, $filename);
+if (!function_exists('scandir')) {
+    function scandir($dirstr) {
+        // php.net/scandir (PHP5)
+        $files = array();
+        $fh = opendir($dirstr);
+        while (false !== ($filename = readdir($fh))) {
+            array_push($files, $filename);
+        }
+        closedir($fh);
+        return $files;
     }
-    closedir($fh);
-    return $files;
 }
 
 /**
