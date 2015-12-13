$NetBSD: patch-src_shared.py,v 1.1 2015/12/13 00:31:54 kamil Exp $

FreeBSD and NetBSD are compatible here.

Patch merged upstream:
https://github.com/Bitmessage/PyBitmessage/pull/812

--- src/shared.py.orig	2014-10-15 21:16:27.000000000 +0000
+++ src/shared.py
@@ -419,8 +419,8 @@ def checkSensitiveFilePermissions(filena
         # TODO: This might deserve extra checks by someone familiar with
         # Windows systems.
         return True
-    elif sys.platform[:7] == 'freebsd':
-        # FreeBSD file systems are the same as major Linux file systems
+    elif sys.platform[:7] == 'freebsd' or sys.platform[:6] == 'netbsd':
+        # BSD file systems are the same as major Linux file systems
         present_permissions = os.stat(filename)[0]
         disallowed_permissions = stat.S_IRWXG | stat.S_IRWXO
         return present_permissions & disallowed_permissions == 0
