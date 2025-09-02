$NetBSD: patch-setup.py,v 1.1 2025/09/02 07:29:46 adam Exp $

Fix version.

--- setup.py.orig	2025-09-02 07:19:35.378073799 +0000
+++ setup.py
@@ -7,7 +7,7 @@ README = (HERE / "README.md").read_text(
 setup(
     name='nvdlib',
     packages=find_packages(include=['nvdlib']),
-    version='0.8.2',
+    version='0.8.3',
     install_requires = ['requests'],
     extras_require={
         "dev": [
