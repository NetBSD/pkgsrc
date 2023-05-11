$NetBSD: patch-setup.py,v 1.2 2023/05/11 09:53:06 adam Exp $

Allow newer crytic-compile.

--- setup.py.orig	2023-05-11 09:50:04.000000000 +0000
+++ setup.py
@@ -71,7 +71,7 @@ setup(
         "ply",
         "rlp",
         "intervaltree",
-        "crytic-compile==0.2.2",
+        "crytic-compile>=0.2.2",
         "wasm",
         "dataclasses; python_version < '3.7'",
         "pyevmasm>=0.2.3",
