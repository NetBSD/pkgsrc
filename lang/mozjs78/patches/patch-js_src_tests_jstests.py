$NetBSD: patch-js_src_tests_jstests.py,v 1.1 2020/12/14 22:45:10 gutteridge Exp $

Get Unix test scaffolding to run on platforms other than Linux and macOS.

--- js/src/tests/jstests.py.orig	2020-11-04 10:51:58.000000000 +0000
+++ js/src/tests/jstests.py
@@ -32,10 +32,10 @@ from lib.tests import RefTestCase, get_j
 from lib.results import ResultsSink, TestOutput
 from lib.progressbar import ProgressBar
 
-if sys.platform.startswith('linux') or sys.platform.startswith('darwin'):
-    from lib.tasks_unix import run_all_tests
-else:
+if sys.platform.startswith('win'):
     from lib.tasks_win import run_all_tests
+else:
+    from lib.tasks_unix import run_all_tests
 
 here = dirname(abspath(__file__))
 
