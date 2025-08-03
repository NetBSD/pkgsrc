$NetBSD: patch-google_____init____.py,v 1.1 2025/08/03 16:35:00 ryoon Exp $

* Do not print runtime deprecated warning.

--- google/__init__.py.orig	2025-07-02 08:15:55.348855525 +0000
+++ google/__init__.py
@@ -1,4 +1,3 @@
-try:
-  __import__('pkg_resources').declare_namespace(__name__)
-except ImportError:
-  __path__ = __import__('pkgutil').extend_path(__path__, __name__)
+from pkgutil import extend_path
+
+__path__ = extend_path(__path__, __name__)
