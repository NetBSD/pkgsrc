$NetBSD: patch-installer_rcube__install.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 853d0ab2a402222cc87dc83bb27c3fb2f33d84aa:
  Fix version selector - do not list versions newer than 0.9.0, use
  "0.9 or newer" instead.

--- installer/rcube_install.php.orig	2013-05-16 18:06:35.000000000 +0000
+++ installer/rcube_install.php
@@ -455,7 +455,8 @@ class rcube_install
         '0.6-beta', '0.6',
         '0.7-beta', '0.7', '0.7.1', '0.7.2', '0.7.3', '0.7.4',
         '0.8-beta', '0.8-rc', '0.8.0', '0.8.1', '0.8.2', '0.8.3', '0.8.4', '0.8.5', '0.8.6',
-        '0.9-beta', '0.9-rc', '0.9-rc2', '0.9.0',
+        '0.9-beta', '0.9-rc', '0.9-rc2',
+        // Note: Do not add newer versions here
     ));
     return $select;
   }
