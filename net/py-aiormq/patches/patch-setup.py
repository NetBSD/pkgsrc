$NetBSD: patch-setup.py,v 1.1 2023/02/10 14:42:48 wiz Exp $

Fix invalid pattern.

--- setup.py.orig	2020-07-28 17:59:58.000000000 +0000
+++ setup.py
@@ -43,7 +43,7 @@ setup(
         "Programming Language :: Python :: Implementation :: PyPy",
         "Programming Language :: Python :: Implementation :: CPython",
     ],
-    python_requires=">3.5.*",
+    python_requires=">3.5",
     package_data={"aiormq": ["py.typed"]},
     extras_require={
         "develop": [
