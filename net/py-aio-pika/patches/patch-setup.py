$NetBSD: patch-setup.py,v 1.1 2023/02/20 08:42:13 wiz Exp $

Fix pattern.

--- setup.py.orig	2020-09-02 20:35:34.000000000 +0000
+++ setup.py
@@ -39,7 +39,7 @@ setup(
     packages=find_packages(exclude=["tests"]),
     package_data={"aio_pika": ["py.typed"]},
     install_requires=["aiormq>=3.2.3,<4", "yarl"],
-    python_requires=">3.5.*, <4",
+    python_requires=">3.5, <4",
     extras_require={
         "develop": [
             "aiomisc~=10.1.6",
