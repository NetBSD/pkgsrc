$NetBSD: patch-duplicity_gpginterface.py,v 1.2 2023/12/18 09:28:38 triaxx Exp $

Provide path to gpg.

--- duplicity/gpginterface.py.orig	2023-10-10 16:25:32.000000000 +0000
+++ duplicity/gpginterface.py
@@ -282,7 +282,7 @@ class GnuPG(object):
     """
 
     def __init__(self):
-        self.call = "gpg"
+        self.call = "@GPGPATH@"
         self.passphrase = None
         self.options = Options()
 
