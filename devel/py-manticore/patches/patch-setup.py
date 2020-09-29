$NetBSD: patch-setup.py,v 1.1 2020/09/29 03:27:32 khorben Exp $

Use the ptable2 Python module to implement prettytable

--- setup.py.orig	2020-06-27 01:54:55.000000000 +0000
+++ setup.py
@@ -54,7 +54,7 @@ setup(
     install_requires=[
         "pyyaml",
         "pysha3",
-        "prettytable",
+        "PTable",
         "ply",
         "rlp",
         "crytic-compile>=0.1.1",
