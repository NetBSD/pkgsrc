$NetBSD: patch-mozilla_build_pgo_profileserver.py,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/build/pgo/profileserver.py.orig	2016-04-07 21:33:18.000000000 +0000
+++ mozilla/build/pgo/profileserver.py
@@ -68,7 +68,7 @@ if __name__ == '__main__':
       env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
       print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-    cmdargs = ["http://localhost:%d/index.html" % PORT]
+    cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
     runner = FirefoxRunner(profile=profile,
                            binary=build.get_binary_path(where="staged-package"),
                            cmdargs=cmdargs,
