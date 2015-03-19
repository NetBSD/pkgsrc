$NetBSD: patch-setup.py,v 1.4 2015/03/19 09:20:30 he Exp $

Do away with the special handling for NetBSD, to avoid PLIST issues
between different pkgsrc-using platforms.
Install helper scripts outside of the config tree (use share/exabgp).
On the other hand, only do the systemd dance on Linux.

--- setup.py.orig	2015-03-14 15:32:13.000000000 +0000
+++ setup.py
@@ -364,14 +364,10 @@ def configuration (etc):
 
 os_name = platform.system()
 
-if os_name == 'NetBSD':
-	files_definition= [
-		('share/exabgp',configuration('etc/exabgp')),
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
 
