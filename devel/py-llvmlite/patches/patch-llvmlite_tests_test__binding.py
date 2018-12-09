$NetBSD: patch-llvmlite_tests_test__binding.py,v 1.1 2018/12/09 20:22:55 adam Exp $

Allow newer LLVM.

--- llvmlite/tests/test_binding.py.orig	2018-11-29 09:48:16.000000000 +0000
+++ llvmlite/tests/test_binding.py
@@ -333,7 +333,6 @@ class TestMisc(BaseTest):
 
     def test_version(self):
         major, minor, patch = llvm.llvm_version_info
-        self.assertEqual((major, minor), (6, 0))
         self.assertIn(patch, range(10))
 
     def test_check_jit_execution(self):
