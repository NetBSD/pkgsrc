$NetBSD: patch-tests_test__vary.py,v 1.1 2023/05/30 07:39:19 wiz Exp $

disuse HTTPResponse.strict
https://github.com/ionrock/cachecontrol/commit/8f037ba1650c446759d6db581012714f6109850f

--- tests/test_vary.py.orig	2020-07-23 15:23:57.000000000 +0000
+++ tests/test_vary.py
@@ -33,7 +33,6 @@ class TestVary(object):
             cached.status == resp.raw.status,
             cached.version == resp.raw.version,
             cached.reason == resp.raw.reason,
-            cached.strict == resp.raw.strict,
             cached.decode_content == resp.raw.decode_content,
         ]
 
