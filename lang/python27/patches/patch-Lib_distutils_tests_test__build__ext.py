$NetBSD: patch-Lib_distutils_tests_test__build__ext.py,v 1.1 2021/06/23 18:30:24 schmonz Exp $

darwin20 support, via MacPorts.

--- Lib/distutils/tests/test_build_ext.py.orig	2021-06-22 19:20:28.000000000 +0000
+++ Lib/distutils/tests/test_build_ext.py
@@ -491,7 +491,7 @@ class BuildExtTestCase(support.TempdirMa
         # format the target value as defined in the Apple
         # Availability Macros.  We can't use the macro names since
         # at least one value we test with will not exist yet.
-        if target[1] < 10:
+        if target[:2] < (10, 10):
             # for 10.1 through 10.9.x -> "10n0"
             target = '%02d%01d0' % target
         else:
