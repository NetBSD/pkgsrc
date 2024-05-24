$NetBSD: patch-duplicity_gpginterface.py,v 1.3 2024/05/24 15:08:39 triaxx Exp $

Replace gpg executable name by absolute path.

--- duplicity/gpginterface.py.orig	2023-10-10 16:25:32.000000000 +0000
+++ duplicity/gpginterface.py
@@ -282,7 +282,7 @@ class GnuPG(object):
     """
 
     def __init__(self):
-        self.call = "gpg"
+        self.call = "@GPG@"
         self.passphrase = None
         self.options = Options()
 
