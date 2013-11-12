$NetBSD: patch-mozilla_build_pgo_profileserver.py,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/build/pgo/profileserver.py.orig	2013-10-23 22:08:50.000000000 +0000
+++ mozilla/build/pgo/profileserver.py
@@ -59,7 +59,7 @@ if __name__ == '__main__':
       env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
       print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-    cmdargs = ["http://localhost:%d/index.html" % PORT]
+    cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
     runner = FirefoxRunner(profile=profile,
                            binary=build.get_binary_path(where="staged-package"),
                            cmdargs=cmdargs,
