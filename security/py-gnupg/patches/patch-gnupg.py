$NetBSD: patch-gnupg.py,v 1.1 2022/01/11 08:45:11 adam Exp $

Look for gpg2 executable.

--- gnupg.py.orig	2022-01-11 08:31:14.000000000 +0000
+++ gnupg.py
@@ -832,7 +832,7 @@ class GPG(object):
     }
 
     "Encapsulate access to the gpg executable"
-    def __init__(self, gpgbinary='gpg', gnupghome=None, verbose=False,
+    def __init__(self, gpgbinary='gpg2', gnupghome=None, verbose=False,
                  use_agent=False, keyring=None, options=None,
                  secret_keyring=None):
         """Initialize a GPG process wrapper.  Options are:
