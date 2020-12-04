$NetBSD: patch-tests_test__find__python__executable.py,v 1.1 2020/12/04 23:29:32 riastradh Exp $

Disable test that expects `python' per se to appear in PATH, which it
generally does not in pkgsrc.

--- tests/test_find_python_executable.py.orig	2020-09-06 10:55:07.000000000 +0000
+++ tests/test_find_python_executable.py
@@ -20,6 +20,7 @@ def test_abs():
 
 
 def test_find_in_path():
+    return
     assert os.path.isabs(find_python_executable("python"))
 
 
