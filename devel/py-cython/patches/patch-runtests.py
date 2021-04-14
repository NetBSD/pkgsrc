$NetBSD: patch-runtests.py,v 1.3 2021/04/14 19:25:15 adam Exp $

Use correct make for pkgsrc.

--- runtests.py.orig	2021-04-14 15:24:45.000000000 +0000
+++ runtests.py
@@ -1773,12 +1773,12 @@ class EmbedTest(unittest.TestCase):
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
@@ -1800,7 +1800,7 @@ class EmbedTest(unittest.TestCase):
 
         try:
             subprocess.check_call([
-                "make",
+                "gmake",
                 "PYTHON='%s'" % sys.executable,
                 "CYTHON='%s'" % cython,
                 "LIBDIR1='%s'" % libdir,
