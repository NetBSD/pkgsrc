$NetBSD: patch-tests_test__etag.py,v 1.1 2023/05/30 07:39:19 wiz Exp $

disuse HTTPResponse.strict
https://github.com/ionrock/cachecontrol/commit/8f037ba1650c446759d6db581012714f6109850f

--- tests/test_etag.py.orig	2022-09-12 14:28:45.000000000 +0000
+++ tests/test_etag.py
@@ -1,6 +1,8 @@
 # SPDX-FileCopyrightText: 2015 Eric Larson
 #
 # SPDX-License-Identifier: Apache-2.0
+from contextlib import ExitStack
+from contextlib import suppress
 
 import pytest
 
@@ -134,11 +136,20 @@ class TestReleaseConnection(object):
 
         resp = Mock(status=304, headers={})
 
-        # This is how the urllib3 response is created in
-        # requests.adapters
-        response_mod = "requests.adapters.HTTPResponse.from_httplib"
+        # These are various ways the the urllib3 response can created
+        # in requests.adapters.  Which one is actually used depends
+        # on which version if `requests` is in use, as well as perhaps
+        # other parameters.
+        response_mods = [
+            "requests.adapters.HTTPResponse.from_httplib",
+            "urllib3.HTTPConnectionPool.urlopen",
+        ]
+
+        with ExitStack() as stack:
+            for mod in response_mods:
+                with suppress(ImportError):
+                    stack.enter_context(patch(mod, Mock(return_value=resp)))
 
-        with patch(response_mod, Mock(return_value=resp)):
             sess.get(etag_url)
             assert resp.read.called
             assert resp.release_conn.called
