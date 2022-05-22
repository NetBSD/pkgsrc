$NetBSD: patch-gnupg.py,v 1.2 2022/05/22 12:17:38 adam Exp $

Look for gpg2 executable.

--- gnupg.py.orig	2022-05-20 08:01:43.000000000 +0000
+++ gnupg.py
@@ -874,7 +874,7 @@ class GPG(object):
     "Encapsulate access to the gpg executable"
 
     def __init__(self,
-                 gpgbinary='gpg',
+                 gpgbinary='gpg2',
                  gnupghome=None,
                  verbose=False,
                  use_agent=False,
