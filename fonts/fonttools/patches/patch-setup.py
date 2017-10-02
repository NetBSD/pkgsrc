$NetBSD: patch-setup.py,v 1.1 2017/10/02 22:08:05 khorben Exp $

Fix path to the manual pages

--- setup.py.orig	2017-08-18 16:49:28.000000000 +0000
+++ setup.py
@@ -264,7 +264,7 @@ class PassCommand(Command):
 		pass
 
 
-def find_data_files(manpath="share/man"):
+def find_data_files(manpath="@PKGMANDIR@"):
 	""" Find FontTools's data_files (just man pages at this point).
 
 	By default, we install man pages to "share/man" directory relative to the
