$NetBSD: patch-runtests.py,v 1.2 2018/10/15 08:21:03 adam Exp $

Use correct make for pkgsrc.

--- runtests.py.orig	2018-10-14 15:27:58.000000000 +0000
+++ runtests.py
@@ -1770,12 +1770,12 @@ class EmbedTest(unittest.TestCase):
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
@@ -1795,7 +1795,7 @@ class EmbedTest(unittest.TestCase):
             cython = os.path.join(CY3_DIR, cython)
         cython = os.path.abspath(os.path.join('..', '..', cython))
         self.assertEqual(0, os.system(
-            "make PYTHON='%s' CYTHON='%s' LIBDIR1='%s' test > make.output" % (sys.executable, cython, libdir)))
+            "gmake PYTHON='%s' CYTHON='%s' LIBDIR1='%s' test > make.output" % (sys.executable, cython, libdir)))
         try:
             os.remove('make.output')
         except OSError:
