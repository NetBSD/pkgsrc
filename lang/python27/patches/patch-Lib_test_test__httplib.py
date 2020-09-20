$NetBSD: patch-Lib_test_test__httplib.py,v 1.1 2020/09/20 11:06:23 mgorny Exp $

--- Lib/test/test_httplib.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/test_httplib.py
@@ -384,6 +384,26 @@ class HeaderTests(TestCase):
             with self.assertRaisesRegexp(ValueError, 'Invalid header'):
                 conn.putheader(name, value)
 
+    def test_invalid_method_names(self):
+        methods = (
+            'GET\r',
+            'POST\n',
+            'PUT\n\r',
+            'POST\nValue',
+            'POST\nHOST:abc',
+            'GET\nrHost:abc\n',
+            'POST\rRemainder:\r',
+            'GET\rHOST:\n',
+            '\nPUT'
+        )
+
+        for method in methods:
+            with self.assertRaisesRegexp(
+                    ValueError, "method can't contain control characters"):
+                conn = httplib.HTTPConnection('example.com')
+                conn.sock = FakeSocket(None)
+                conn.request(method=method, url="/")
+
 
 class BasicTest(TestCase):
     def test_status_lines(self):
