$NetBSD: patch-program_lib_Roundcube_rcube__mime.php,v 1.3 2020/06/07 22:07:04 taca Exp $

Fix path to /etc/.

--- program/lib/Roundcube/rcube_mime.php.orig	2018-04-11 11:06:18.000000000 +0000
+++ program/lib/Roundcube/rcube_mime.php
@@ -790,12 +790,12 @@ class rcube_mime
             $file_paths[] = 'C:/xampp/apache/conf/mime.types.';
         }
         else {
-            $file_paths[] = '/etc/mime.types';
-            $file_paths[] = '/etc/httpd/mime.types';
-            $file_paths[] = '/etc/httpd2/mime.types';
-            $file_paths[] = '/etc/apache/mime.types';
-            $file_paths[] = '/etc/apache2/mime.types';
-            $file_paths[] = '/etc/nginx/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/httpd/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/httpd2/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/apache/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/apache2/mime.types';
+            $file_paths[] = '@PKG_SYSCONFBASE@/nginx/mime.types';
             $file_paths[] = '/usr/local/etc/httpd/conf/mime.types';
             $file_paths[] = '/usr/local/etc/apache/conf/mime.types';
             $file_paths[] = '/usr/local/etc/apache24/mime.types';
