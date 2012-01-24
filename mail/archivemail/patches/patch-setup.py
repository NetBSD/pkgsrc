$NetBSD: patch-setup.py,v 1.1 2012/01/24 11:49:33 obache Exp $

* Let not to force Linux FHS compliant for manpath.

--- setup.py.orig	2011-07-09 17:09:57.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 #! /usr/bin/env python
 
 import sys
+import os
 
 def check_python_version(): 
     """Abort if we are running on python < v2.0"""
@@ -29,5 +30,5 @@ setup(name="archivemail",
       maintainer="Nikolaus Schulz, Peter Poeml",
       maintainer_email="nikosch@users.sourceforge.net, poeml@users.sourceforge.net",
       scripts=["archivemail"],
-      data_files=[("share/man/man1", ["archivemail.1"])],
+      data_files=[(os.environ["PKGMANDIR"] + "/man1", ["archivemail.1"])],
       )
