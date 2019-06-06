$NetBSD: patch-pysollib_pysolrandom.py,v 1.1 2019/06/06 21:53:44 adam Exp $

Use standard random module.

--- pysollib/pysolrandom.py.orig	2019-06-06 19:34:50.000000000 +0000
+++ pysollib/pysolrandom.py
@@ -30,9 +30,7 @@ from pysollib.mfxutil import SubclassRes
 try:
     import random2
 except ImportError:
-    raise ImportError(
-        "You need to install " +
-        "https://pypi.python.org/pypi/random2 using pip or similar.")
+    import random as random2
 
 
 # ************************************************************************
