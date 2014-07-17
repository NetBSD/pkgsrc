$NetBSD: patch-Lib_multiprocessing_process.py,v 1.1 2014/07/17 15:26:49 ryoon Exp $

--- Lib/multiprocessing/process.py.orig	2014-06-30 02:05:29.000000000 +0000
+++ Lib/multiprocessing/process.py
@@ -306,7 +306,15 @@ class _MainProcess(Process):
         self._popen = None
         self._counter = itertools.count(1)
         self._children = set()
-        self._authkey = AuthenticationString(os.urandom(32))
+        # Get randomness from urandom or the 'random' module.
+        # from http://bugs.python.org/issue6645
+        # for SCO OpenServer 5.0.7/3.2 and AIX
+        try:
+            self._authkey = AuthenticationString(os.urandom(32))
+        except:
+            import random
+            bytes = [chr(random.randrange(256)) for i in range(32)]
+            self._authkey = AuthenticationString(bytes)
         self._tempdir = None
 
 _current_process = _MainProcess()
