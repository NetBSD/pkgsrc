$NetBSD: patch-.._Archive__Tar-1.4.5_Archive_Tar.php,v 1.1 2019/02/07 13:40:57 taca Exp $

* Fix from Archive_Tar-1.4.6.

--- ../Archive_Tar-1.4.5/Archive/Tar.php.orig	2019-01-02 21:45:20.000000000 +0000
+++ ../Archive_Tar-1.4.5/Archive/Tar.php
@@ -1770,11 +1770,8 @@ class Archive_Tar extends PEAR
         if (strpos($file, 'phar://') === 0) {
             return true;
         }
-        if (strpos($file, DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR) !== false) {
-            return true;
-        }
-        if (strpos($file, '..' . DIRECTORY_SEPARATOR) === 0) {
-            return true;
+        if (strpos($file, '../') !== false || strpos($file, '..\\') !== false) {
+                return true;
         }
         return false;
     }
