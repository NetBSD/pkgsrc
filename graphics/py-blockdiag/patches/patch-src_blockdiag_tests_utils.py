$NetBSD: patch-src_blockdiag_tests_utils.py,v 1.1 2011/12/12 11:33:28 obache Exp $

* Fix testcase using 'with' statement are failed in python2.5 environment
  https://bitbucket.org/tk0miya/blockdiag/changeset/f078235db9b9

--- src/blockdiag/tests/utils.py.orig	2011-11-13 08:30:10.000000000 +0000
+++ src/blockdiag/tests/utils.py
@@ -38,6 +38,24 @@ def stderr_wrapper(func):
     return wrap
 
 
+def assertRaises(exc):
+    def decorator(func):
+        def fn(self, *args, **kwargs):
+            try:
+                func(self, *args, **kwargs)
+            except exc:
+                pass
+            else:
+                msg = '%s does not raise exceptions: %s' % \
+                      (func.__name__, str(exc))
+                self.fail(msg)
+
+        fn.__name__ = func.__name__
+        return fn
+
+    return decorator
+
+
 def __build_diagram(filename):
     import os
     testdir = os.path.dirname(__file__)
