$NetBSD: patch-tests_test__find__python__executable.py,v 1.2 2024/11/03 07:50:30 adam Exp $

Disable test that expects `python' per se to appear in PATH, which it
generally does not in pkgsrc.

--- tests/test_find_python_executable.py.orig	2024-11-02 16:21:55.873429800 +0000
+++ tests/test_find_python_executable.py
@@ -23,6 +23,7 @@ def test_abs():
 
 
 def test_find_in_path():
+    return
     assert isabs(find_python_executable("python"))
 
 
