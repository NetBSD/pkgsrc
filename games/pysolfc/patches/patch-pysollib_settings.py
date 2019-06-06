$NetBSD: patch-pysollib_settings.py,v 1.1 2019/06/06 21:53:44 adam Exp $

Use custom data dir.

--- pysollib/settings.py.orig	2008-11-15 13:04:30.000000000 -0800
+++ pysollib/settings.py	2008-11-15 13:05:05.000000000 -0800
@@ -61,10 +61,7 @@ DATA_DIRS = []
 # you can add your extra directories here
 if os.name == 'posix':
     DATA_DIRS = [
-        '/usr/share/PySolFC',
-        '/usr/local/share/PySolFC',
-        '/usr/games/PySolFC',
-        '/usr/local/games/PySolFC',
+        '@DATADIR@'
         ]
 if os.name == 'nt':
     pass
