$NetBSD: patch-setup.py,v 1.1 2017/04/08 21:40:54 adam Exp $

Do not install LICENSE, especially not into PREFIX.

--- setup.py.orig	2017-04-08 21:35:17.000000000 +0000
+++ setup.py
@@ -112,7 +112,6 @@ setup(
 
     # in addition, the following will make the specified files go
     # into source _and_ bdist distributions!
-    data_files=[('.', ['LICENSE'])],
 
     # this package does not access its own source code or data files
     # as normal operating system files
