$NetBSD: patch-sx_pisa3_pisa__context.py,v 1.1 2018/01/08 22:11:06 joerg Exp $

--- sx/pisa3/pisa_context.py.orig	2018-01-08 14:18:52.579405122 +0000
+++ sx/pisa3/pisa_context.py
@@ -40,7 +40,10 @@ from reportlab.lib.fonts import addMappi
 
 from sx.w3c import css, cssDOMElementInterface
 
-from html5lib.sanitizer import *
+try:
+    from html5lib.filters.sanitizer import *
+except ImportError:
+    from html5lib.sanitizer import *
 
 import logging
 log = logging.getLogger("ho.pisa")
