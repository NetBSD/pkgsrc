$NetBSD: patch-build_detectsys.py,v 1.1 2012/08/26 09:07:23 marino Exp $

Set os to "dragonfly" when built on "DragonFly"

--- build/detectsys.py.orig	2012-08-12 12:29:37.000000000 +0000
+++ build/detectsys.py
@@ -58,7 +58,7 @@ def detectOS():
 	Raises ValueError if no known OS is detected.
 	'''
 	os = system().lower()
-	if os in ('linux', 'darwin', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
+	if os in ('linux', 'darwin', 'dragonfly', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
 		return os
 	elif os.startswith('gnu/'):
 		# GNU userland on non-Hurd kernel, for example Debian GNU/kFreeBSD.
