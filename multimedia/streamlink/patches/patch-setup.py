$NetBSD: patch-setup.py,v 1.3 2026/03/02 20:31:12 yhardy Exp $

Install manpages in ${PKGMANDIR}.

--- setup.py.orig	2025-11-11 16:12:14.488784600 +0000
+++ setup.py
@@ -1,4 +1,5 @@
 import sys
+from os import getenv, path
 from textwrap import dedent
 
 
@@ -59,7 +60,7 @@ data_files = [
     # man page:
     #  requires the pre-built man page file via sphinx ("docs" dependency group)
     #  `make --directory=docs clean man`
-    ("share/man/man1", ["docs/_build/man/streamlink.1"]),
+    (getenv("PKGMANDIR") + "/man1", ["docs/_build/man/streamlink.1"]),
 ]
 data_files = [
     (destdir, [file for file in srcfiles if Path(file).exists()])
