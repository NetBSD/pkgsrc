$NetBSD: patch-python_vmailmgr_____init____.py,v 1.1 2024/02/27 19:13:43 schmonz Exp $

Port to Python 3, maintaining 2.7 compatibility.

--- python/vmailmgr/__init__.py.orig	2015-09-01 16:03:21.000000000 +0000
+++ python/vmailmgr/__init__.py
@@ -1 +1 @@
-from commands import *
+from vmailmgr.commands import *
