$NetBSD: patch-coherence_____init____.py,v 1.2 2020/04/20 00:42:52 joerg Exp $

twisted 16.0.0 detection is broken, see
https://github.com/coherence-project/Coherence/issues/25

--- coherence/__init__.py.orig	2010-01-02 15:35:20.000000000 +0000
+++ coherence/__init__.py
@@ -11,8 +11,7 @@ SERVER_ID = ','.join([platform.system(),
 
 
 try:
-    from twisted import version as twisted_version
-    from twisted.web import version as twisted_web_version
+    from twisted import __version__ as twisted_version
     from twisted.python.versions import Version
 except ImportError, exc:
     # log error to stderr, might be useful for debugging purpose
@@ -24,8 +23,6 @@ try:
     if twisted_version < Version("twisted", 2, 5, 0):
         raise ImportError("Twisted >= 2.5 is required. Please install it.")
 
-    if twisted_web_version < Version("twisted.web", 2, 5, 0):
-        raise ImportError("Twisted.Web >= 2.5 is required. Please install it")
 except ImportError, exc:
     # log error to stderr, might be useful for debugging purpose
     for arg in exc.args:
