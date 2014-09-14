$NetBSD: patch-runtests.py,v 1.1 2014/09/14 17:44:49 wiz Exp $

Use correct make for pkgsrc.

--- runtests.py.orig	2014-09-10 15:49:05.000000000 +0000
+++ runtests.py
@@ -1450,12 +1450,12 @@ class EmbedTest(unittest.TestCase):
         self.old_dir = os.getcwd()
         os.chdir(self.working_dir)
         os.system(
-            "make PYTHON='%s' clean > /dev/null" % sys.executable)
+            "gmake PYTHON='%s' clean > /dev/null" % sys.executable)
 
     def tearDown(self):
         try:
             os.system(
-                "make PYTHON='%s' clean > /dev/null" % sys.executable)
+                "gmake PYTHON='%s' clean > /dev/null" % sys.executable)
         except:
             pass
         os.chdir(self.old_dir)
@@ -1476,7 +1476,7 @@ class EmbedTest(unittest.TestCase):
             cython = os.path.join(CY3_DIR, cython)
         cython = os.path.abspath(os.path.join('..', '..', cython))
         self.assert_(os.system(
-            "make PYTHON='%s' CYTHON='%s' LIBDIR1='%s' test > make.output" % (sys.executable, cython, libdir)) == 0)
+            "gmake PYTHON='%s' CYTHON='%s' LIBDIR1='%s' test > make.output" % (sys.executable, cython, libdir)) == 0)
         try:
             os.remove('make.output')
         except OSError:
