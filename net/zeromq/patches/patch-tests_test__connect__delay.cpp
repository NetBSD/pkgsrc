$NetBSD: patch-tests_test__connect__delay.cpp,v 1.1 2013/07/30 04:00:25 obache Exp $

* error: no newline at end of file

--- tests/test_connect_delay.cpp.orig	2013-05-02 08:55:49.000000000 +0000
+++ tests/test_connect_delay.cpp
@@ -257,4 +257,5 @@ int main (void)
     
     rc = zmq_ctx_destroy(context2);
     assert (rc == 0);
-}
\ No newline at end of file
+}
+
