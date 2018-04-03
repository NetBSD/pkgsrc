$NetBSD: patch-zenmap_test_run__tests.py,v 1.3 2018/04/03 14:34:00 adam Exp $

--- zenmap/test/run_tests.py.orig	2017-08-07 16:14:51.000000000 +0000
+++ zenmap/test/run_tests.py
@@ -11,6 +11,7 @@ if __name__ == "__main__":
         sys.exit(0)
 
     os.chdir("..")
+    sys.path.insert(1, "build/lib")
     suite = unittest.defaultTestLoader.discover(
         start_dir=glob.glob("build/lib*")[0],
         pattern="*.py"
