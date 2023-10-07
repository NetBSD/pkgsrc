$NetBSD: patch-python_recoll_recoll_rclconfig.py,v 1.1 2023/10/07 06:21:32 wiz Exp $

From upstream.

--- python/recoll/recoll/rclconfig.py.orig	2023-06-20 11:38:17.000000000 +0000
+++ python/recoll/recoll/rclconfig.py	2023-10-06 21:32:49.383889924 +0000
@@ -46,42 +46,23 @@
                 self.confdir = os.path.expanduser("~/.recoll")
         #print("Confdir: [%s]" % self.confdir, file=sys.stderr)
         
-        # Also find datadir. This is trickier because this is set by
-        # "configure" in the C code. We can only do our best. Have to
-        # choose a preference order. Use RECOLL_DATADIR if the order is wrong
+        # Find datadir to get at the base configuration files. This could be a bit tricky because
+        # this is set by "configure" in the C code. Use RECOLL_DATADIR if the computed value is
+        # wrong.
         self.datadir = None
         if "RECOLL_DATADIR" in os.environ:
             self.datadir = os.environ["RECOLL_DATADIR"]
         else:
-            if platsys == "Windows":
-                dirs = (os.path.join(os.path.dirname(sys.argv[0]), "..", ".."),
-                        "C:/Program Files (X86)/Recoll/",
-                        "C:/Program Files/Recoll/",
-                        "C:/install/recoll/")
-                for dir in dirs:
-                    if os.path.exists(os.path.join(dir, "Share")):
-                        self.datadir = os.path.join(dir, "Share")
-                        break
-            elif platsys == "Darwin":
-                # Actually, I'm not sure why we don't do this on all platforms
-                self.datadir = os.path.join(os.path.dirname(sys.argv[0]), "..")
-                #print("Mac datadir: [%s]" % self.datadir, file=sys.stderr)
-            else:
-                dirs = ("/opt/local", "/opt", "/usr", "/usr/local")
-                for dir in dirs:
-                    dd = os.path.join(dir, "share/recoll")
-                    if os.path.exists(dd):
-                        self.datadir = dd
-        if self.datadir is None:
-            self.datadir = "/usr/share/recoll"
+            self.datadir = os.path.join(os.path.dirname(sys.argv[0]), "..")
+        recollconf = os.path.join(self.datadir, "examples", "recoll.conf")
         f = None
         try:
-            f = open(os.path.join(self.datadir, "examples", "recoll.conf"), "r")
+            f = open(recollconf, "r")
         except:
             pass
         if f is None:
             raise(Exception(
-                "Can't open default/system recoll.conf. " +
+                f"Can't open default/system config: {recollconf} " +
                 "Please set RECOLL_DATADIR in the environment to point " +
                 "to the installed recoll data files."))
         else:
