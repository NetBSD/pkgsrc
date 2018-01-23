$NetBSD: patch-lexicon_providers_namecheap.py,v 1.1 2018/01/23 10:54:20 fhajny Exp $

Make namecheap support truly optional as promised.
https://github.com/AnalogJ/lexicon/issues/163

--- lexicon/providers/namecheap.py.orig	2018-01-22 17:28:26.000000000 +0000
+++ lexicon/providers/namecheap.py
@@ -3,7 +3,10 @@ from __future__ import print_function
 
 import logging
 
-import namecheap
+try:
+    import namecheap #optional dep
+except ImportError:
+    pass
 
 from .base import Provider as BaseProvider
 
