$NetBSD: patch-scapy_____init____.py,v 1.1 2024/10/01 01:08:29 gutteridge Exp $

Supply expected version, not inconsistent date value set by upstream.

--- scapy/__init__.py.orig	2024-09-28 13:11:32.000000000 +0000
+++ scapy/__init__.py
@@ -133,7 +133,7 @@ def _version():
     # Method 0: from external packaging
     try:
         # possibly forced by external packaging
-        return os.environ['SCAPY_VERSION']
+        return "@PKGVERSION_NOREV@"
     except KeyError:
         pass
 
