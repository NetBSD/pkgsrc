$NetBSD: patch-breezy_tests_test__server.py,v 1.1 2019/10/27 13:05:46 rhialto Exp $

Stub out call to shutdown() since it mysteriously fails with 
an OSError exception with EINVAL.
See https://bugs.launchpad.net/brz/+bug/1849971

--- breezy/tests/test_server.py.orig	2019-06-16 22:18:58.000000000 +0000
+++ breezy/tests/test_server.py
@@ -381,7 +381,7 @@ class TestingTCPServerMixin(object):
         socket.
         """
         try:
-            sock.shutdown(socket.SHUT_RDWR)
+            # sock.shutdown(socket.SHUT_RDWR) # fails with EINVAL
             sock.close()
         except Exception as e:
             if self.ignored_exceptions(e):
