$NetBSD: patch-tests_tlstest.py,v 1.1 2017/01/01 21:50:31 schmonz Exp $

Allow installation with multiple Python versions.

--- tests/tlstest.py.orig	2014-11-13 02:22:47.000000000 +0000
+++ tests/tlstest.py
@@ -51,7 +51,7 @@ def printUsage(s=None):
         crypto = "Python crypto"        
     if s:
         print("ERROR: %s" % s)
-    print("""\ntls.py version %s (using %s)  
+    print("""\ntls@PYVERSSUFFIX@.py version %s (using %s)  
 
 Commands:
   server HOST:PORT DIRECTORY
