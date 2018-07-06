$NetBSD: patch-build_detectsys.py,v 1.3 2018/07/06 03:33:17 ryoon Exp $

Support evbarm and similar variants.

--- build/detectsys.py.orig	2017-08-03 10:26:28.000000000 +0000
+++ build/detectsys.py
@@ -24,7 +24,7 @@ def detectCPU():
 		return 'x86'
 	elif cpu.startswith('ppc') or cpu.endswith('ppc') or cpu.startswith('power'):
 		return 'ppc64' if cpu.endswith('64') else 'ppc'
-	elif cpu.startswith('arm'):
+	elif cpu.startswith('arm') or cpu.endswith('arm'):
 		return 'arm'
 	elif cpu == 'aarch64':
 		return 'aarch64'
