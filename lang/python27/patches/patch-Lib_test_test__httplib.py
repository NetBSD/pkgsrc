$NetBSD: patch-Lib_test_test__httplib.py,v 1.3.8.1 2021/10/13 21:04:01 tm Exp $

bpo-39603 (CVE-2020-26116): header injection via HTTP method

Taken from:
https://gitweb.gentoo.org/fork/cpython.git/commit/?h=gentoo-2.7-vanilla&id=138e2caeb4827ccfd1eaff2cf63afb79dfeeb3c4

Fix CVE-2021-3737: http client infinite line reading (DoS) after a HTTP 100 Continue
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00368-CVE-2021-3737.patch

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
@@ -655,6 +675,14 @@ class BasicTest(TestCase):
         resp = httplib.HTTPResponse(FakeSocket(body))
         self.assertRaises(httplib.LineTooLong, resp.begin)
 
+    def test_overflowing_header_limit_after_100(self):
+        body = (
+            'HTTP/1.1 100 OK\r\n'
+            'r\n' * 32768
+        )
+        resp = httplib.HTTPResponse(FakeSocket(body))
+        self.assertRaises(httplib.HTTPException, resp.begin)
+
     def test_overflowing_chunked_line(self):
         body = (
             'HTTP/1.1 200 OK\r\n'
