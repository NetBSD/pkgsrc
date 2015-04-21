$NetBSD: patch-build_detectsys.py,v 1.2 2015/04/21 17:07:29 joerg Exp $

Set os to "dragonfly" when built on "DragonFly"
Support evbarm and similar variants.

--- build/detectsys.py.orig	2012-08-12 12:29:37.000000000 +0000
+++ build/detectsys.py
@@ -23,7 +23,7 @@ def detectCPU():
 		return 'x86'
 	elif cpu.startswith('ppc') or cpu.endswith('ppc') or cpu.startswith('power'):
 		return 'ppc64' if cpu.endswith('64') else 'ppc'
-	elif cpu.startswith('arm'):
+	elif cpu.startswith('arm') or cpu.endswith('arm'):
 		return 'arm'
 	elif cpu.startswith('mips'):
 		return 'mipsel' if cpu.endswith('el') else 'mips'
@@ -58,7 +58,7 @@ def detectOS():
 	Raises ValueError if no known OS is detected.
 	'''
 	os = system().lower()
-	if os in ('linux', 'darwin', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
+	if os in ('linux', 'darwin', 'dragonfly', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
 		return os
 	elif os.startswith('gnu/'):
 		# GNU userland on non-Hurd kernel, for example Debian GNU/kFreeBSD.
