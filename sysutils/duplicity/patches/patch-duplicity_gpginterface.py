$NetBSD: patch-duplicity_gpginterface.py,v 1.1 2021/02/11 10:40:35 adam Exp $

Provide path to gpg.

--- duplicity/gpginterface.py.orig	2020-11-18 20:05:43.000000000 +0000
+++ duplicity/gpginterface.py
@@ -286,7 +286,7 @@ class GnuPG(object):
     """
 
     def __init__(self):
-        self.call = u'gpg'
+        self.call = u'@GPGPATH@'
         self.passphrase = None
         self.options = Options()
 
