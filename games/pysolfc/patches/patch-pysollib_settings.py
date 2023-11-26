$NetBSD: patch-pysollib_settings.py,v 1.3 2023/11/26 16:45:02 adam Exp $

Use custom data dir.

--- pysollib/settings.py.orig	2023-07-11 01:24:10.000000000 +0000
+++ pysollib/settings.py
@@ -61,11 +61,7 @@ DATA_DIRS = []
 # you can add your extra directories here
 if os.name == 'posix':
     DATA_DIRS = [
-        '/app/share/PySolFC',
-        '/usr/share/PySolFC',
-        '/usr/local/share/PySolFC',
-        '/usr/share/games/PySolFC',
-        '/usr/local/share/games/PySolFC',
+        '@DATADIR@'
         ]
 if os.name == 'nt':
     pass
