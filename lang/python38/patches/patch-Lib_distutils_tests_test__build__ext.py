$NetBSD: patch-Lib_distutils_tests_test__build__ext.py,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/distutils/tests/test_build_ext.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ Lib/distutils/tests/test_build_ext.py
@@ -492,7 +492,7 @@ class BuildExtTestCase(TempdirManager,
         # format the target value as defined in the Apple
         # Availability Macros.  We can't use the macro names since
         # at least one value we test with will not exist yet.
-        if target[1] < 10:
+        if target[:2] < (10, 10):
             # for 10.1 through 10.9.x -> "10n0"
             target = '%02d%01d0' % target
         else:
