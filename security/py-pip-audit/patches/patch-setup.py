$NetBSD: patch-setup.py,v 1.1 2021/11/16 16:04:40 wiz Exp $

Do not insist on one particular version of CacheControl.

--- setup.py.orig	2021-11-09 22:42:57.000000000 +0000
+++ setup.py
@@ -35,7 +35,7 @@ setup(
         "progress>=1.6",
         "resolvelib>=0.8.0",
         "html5lib>=1.1",
-        "CacheControl==0.12.10",
+        "CacheControl>=0.12.10",
         "lockfile>=0.12.2",
     ],
     extras_require={
