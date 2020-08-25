$NetBSD: patch-chirp_platform.py,v 1.2 2020/08/25 13:45:53 gdt Exp $

This software contains darwin specific tweaks which do not apply to pkgsrc

--- chirp/platform.py.orig	2017-10-12 18:01:04.000000000 +1100
+++ chirp/platform.py	2020-07-03 15:33:43.225703607 +1000
@@ -283,16 +283,6 @@
 
         Platform.__init__(self, basepath)
 
-        # This is a hack that needs to be properly fixed by importing the
-        # latest changes to this module from d-rats.  In the interest of
-        # time, however, I'll throw it here
-        if sys.platform == "darwin":
-            if "DISPLAY" not in os.environ:
-                LOG.info("Forcing DISPLAY for MacOS")
-                os.environ["DISPLAY"] = ":0"
-
-            os.environ["PANGO_RC_FILE"] = "../Resources/etc/pango/pangorc"
-
     def default_dir(self):
         return os.path.abspath(os.getenv("HOME"))
 
