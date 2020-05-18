$NetBSD: patch-setup.py,v 1.1 2020/05/18 15:11:01 wiz Exp $

Avoid hardcoding particular module versions.

--- setup.py.orig	2020-04-20 11:29:57.000000000 +0000
+++ setup.py
@@ -48,9 +48,9 @@ docs_require = [
 ]
 
 tests_require = [
-    "mock==3.0.5",
-    "pytest==4.5.0",
-    "pytest-asyncio==0.10.0"
+    "mock",
+    "pytest",
+    "pytest-asyncio",
 ]
 
 # pip install pygls
