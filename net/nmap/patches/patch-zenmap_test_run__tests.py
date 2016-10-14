$NetBSD: patch-zenmap_test_run__tests.py,v 1.2 2016/10/14 15:11:16 maya Exp $

--- zenmap/test/run_tests.py.orig	2016-06-26 04:39:29.000000000 +0000
+++ zenmap/test/run_tests.py
@@ -11,8 +11,9 @@ if __name__ == "__main__":
         sys.exit(0)
 
     os.chdir("..")
+    sys.path.insert(1,"build/lib")
     suite = unittest.defaultTestLoader.discover(
-        start_dir=glob.glob("build/lib.*")[0],
+        start_dir=glob.glob("build/lib/*")[0],
         pattern="*.py"
         )
     unittest.TextTestRunner().run(suite)
