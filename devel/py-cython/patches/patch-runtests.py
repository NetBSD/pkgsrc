$NetBSD: patch-runtests.py,v 1.4 2023/11/13 10:27:15 wiz Exp $

Use correct make for pkgsrc.

--- runtests.py.orig	2023-10-30 22:33:17.813828000 +0000
+++ runtests.py
@@ -2092,12 +2092,12 @@ class EmbedTest(unittest.TestCase):
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
@@ -2116,7 +2116,7 @@ class EmbedTest(unittest.TestCase):
 
         try:
             subprocess.check_output([
-                    "make",
+                    "gmake",
                     "PYTHON='%s'" % sys.executable,
                     "CYTHON='%s'" % cython,
                     "LIBDIR1='%s'" % libdir,
