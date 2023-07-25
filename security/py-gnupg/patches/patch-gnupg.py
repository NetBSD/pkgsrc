$NetBSD: patch-gnupg.py,v 1.3 2023/07/25 08:08:54 adam Exp $

Look for gpg2 executable.

--- gnupg.py.orig	2023-07-22 09:48:02.000000000 +0000
+++ gnupg.py
@@ -1029,7 +1029,7 @@ class GPG(object):
     "A map of GPG operations to result object types."
 
     def __init__(self,
-                 gpgbinary='gpg',
+                 gpgbinary='gpg2',
                  gnupghome=None,
                  verbose=False,
                  use_agent=False,
