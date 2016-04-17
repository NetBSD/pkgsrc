$NetBSD: patch-coherence_____init____.py,v 1.1 2016/04/17 10:15:21 wiz Exp $

twisted 16.0.0 detection is broken, see
https://github.com/coherence-project/Coherence/issues/25

--- coherence/__init__.py.orig	2010-01-02 15:35:20.000000000 +0000
+++ coherence/__init__.py
@@ -24,8 +24,6 @@ try:
     if twisted_version < Version("twisted", 2, 5, 0):
         raise ImportError("Twisted >= 2.5 is required. Please install it.")
 
-    if twisted_web_version < Version("twisted.web", 2, 5, 0):
-        raise ImportError("Twisted.Web >= 2.5 is required. Please install it")
 except ImportError, exc:
     # log error to stderr, might be useful for debugging purpose
     for arg in exc.args:
