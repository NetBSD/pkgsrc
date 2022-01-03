$NetBSD: patch-pysollib_settings.py,v 1.2 2022/01/03 10:55:26 wiz Exp $

Use custom data dir.

--- pysollib/settings.py.orig	2021-12-11 00:44:30.000000000 +0000
+++ pysollib/settings.py
@@ -61,10 +61,7 @@ DATA_DIRS = []
 # you can add your extra directories here
 if os.name == 'posix':
     DATA_DIRS = [
-        '/usr/share/PySolFC',
-        '/usr/local/share/PySolFC',
-        '/usr/share/games/PySolFC',
-        '/usr/local/share/games/PySolFC',
+        '@DATADIR@'
         ]
 if os.name == 'nt':
     pass
