$NetBSD: patch-Lib_test_test__urllib2.py,v 1.3 2021/06/23 18:30:24 schmonz Exp $

bpo-39503 (CVE-2020-8492): ReDoS on AbstractBasicAuthHandler

taken from:
https://gitweb.gentoo.org/fork/cpython.git/commit/?h=gentoo-2.7-vanilla&id=2273e65e11dd0234f2f51ebaef61fc6e848d4059

--- Lib/test/test_urllib2.py.orig	2021-06-22 19:20:43.000000000 +0000
+++ Lib/test/test_urllib2.py
@@ -1128,42 +1128,67 @@ class HandlerTests(unittest.TestCase):
         self.assertEqual(req.get_host(), "proxy.example.com:3128")
         self.assertEqual(req.get_header("Proxy-authorization"),"FooBar")
 
-    def test_basic_auth(self, quote_char='"'):
+    def check_basic_auth(self, headers, realm):
         opener = OpenerDirector()
         password_manager = MockPasswordManager()
         auth_handler = urllib2.HTTPBasicAuthHandler(password_manager)
-        realm = "ACME Widget Store"
-        http_handler = MockHTTPHandler(
-            401, 'WWW-Authenticate: Basic realm=%s%s%s\r\n\r\n' %
-            (quote_char, realm, quote_char) )
+        body = '\r\n'.join(headers) + '\r\n\r\n'
+        http_handler = MockHTTPHandler(401, body)
         opener.add_handler(auth_handler)
         opener.add_handler(http_handler)
         self._test_basic_auth(opener, auth_handler, "Authorization",
                               realm, http_handler, password_manager,
                               "http://acme.example.com/protected",
-                              "http://acme.example.com/protected"
-                             )
-
-    def test_basic_auth_with_single_quoted_realm(self):
-        self.test_basic_auth(quote_char="'")
-
-    def test_basic_auth_with_unquoted_realm(self):
-        opener = OpenerDirector()
-        password_manager = MockPasswordManager()
-        auth_handler = urllib2.HTTPBasicAuthHandler(password_manager)
-        realm = "ACME Widget Store"
-        http_handler = MockHTTPHandler(
-            401, 'WWW-Authenticate: Basic realm=%s\r\n\r\n' % realm)
-        opener.add_handler(auth_handler)
-        opener.add_handler(http_handler)
-        msg = "Basic Auth Realm was unquoted"
-        with test_support.check_warnings((msg, UserWarning)):
-            self._test_basic_auth(opener, auth_handler, "Authorization",
-                                  realm, http_handler, password_manager,
-                                  "http://acme.example.com/protected",
-                                  "http://acme.example.com/protected"
-                                 )
+                              "http://acme.example.com/protected")
 
+    def test_basic_auth(self):
+        realm = "realm2@example.com"
+        realm2 = "realm2@example.com"
+        basic = 'Basic realm="{realm}"'.format(realm=realm)
+        basic2 = 'Basic realm="{realm2}"'.format(realm2=realm2)
+        other_no_realm = 'Otherscheme xxx'
+        digest = ('Digest realm="{realm2}", '
+                  'qop="auth, auth-int", '
+                  'nonce="dcd98b7102dd2f0e8b11d0f600bfb0c093", '
+                  'opaque="5ccc069c403ebaf9f0171e9517f40e41"'
+                  .format(realm2=realm2))
+        for realm_str in (
+            # test "quote" and 'quote'
+            'Basic realm="{realm}"'.format(realm=realm),
+            "Basic realm='{realm}'".format(realm=realm),
+
+            # charset is ignored
+            'Basic realm="{realm}", charset="UTF-8"'.format(realm=realm),
+
+            # Multiple challenges per header
+            ', '.join((basic, basic2)),
+            ', '.join((basic, other_no_realm)),
+            ', '.join((other_no_realm, basic)),
+            ', '.join((basic, digest)),
+            ', '.join((digest, basic)),
+        ):
+            headers = ['WWW-Authenticate: {realm_str}'
+                       .format(realm_str=realm_str)]
+            self.check_basic_auth(headers, realm)
+
+        # no quote: expect a warning
+        with test_support.check_warnings(("Basic Auth Realm was unquoted",
+                                     UserWarning)):
+            headers = ['WWW-Authenticate: Basic realm={realm}'
+                       .format(realm=realm)]
+            self.check_basic_auth(headers, realm)
+
+        # Multiple headers: one challenge per header.
+        # Use the first Basic realm.
+        for challenges in (
+            [basic,  basic2],
+            [basic,  digest],
+            [digest, basic],
+        ):
+            headers = ['WWW-Authenticate: {challenge}'
+                       .format(challenge=challenge)
+                       for challenge in challenges]
+            self.check_basic_auth(headers, realm)
 
     def test_proxy_basic_auth(self):
         opener = OpenerDirector()
