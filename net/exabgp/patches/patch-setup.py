$NetBSD: patch-setup.py,v 1.3 2015/02/19 12:23:52 he Exp $

Do away with the special handling for NetBSD, to avoid PLIST issues.
Install helper scripts outside of the config tree (use share/exabgp).
On the other hand, only do the systemd dance on Linux.

--- setup.py.orig	2015-01-08 09:15:39.000000000 +0000
+++ setup.py
@@ -371,14 +371,10 @@ def configuration (etc):
 
 os_name = platform.system()
 
-if os_name == 'NetBSD':
-	files_definition= [
-		('bin/exabgp',configuration('etc/exabgp')),
-	]
-else:
-	files_definition = [
-		('etc/exabgp',configuration('etc/exabgp')),
-	]
+files_definition= [
+	('share/exabgp',configuration('etc/exabgp')),
+]
+if os_name == 'Linux':
 	if sys.argv[-1] == 'systemd':
 		files_definition.append(('/usr/lib/systemd/system',configuration('etc/systemd')))
 
