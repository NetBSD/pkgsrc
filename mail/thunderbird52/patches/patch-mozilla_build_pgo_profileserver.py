$NetBSD: patch-mozilla_build_pgo_profileserver.py,v 1.1 2018/12/16 08:29:48 ryoon Exp $

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
