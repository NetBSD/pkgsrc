$NetBSD: patch-chirp_platform.py,v 1.1 2014/07/21 07:57:21 dbj Exp $
This software contains darwin specific tweaks which do not apply to pkgsrc

--- chirp/platform.py.orig	2014-04-29 03:55:43.000000000 +0000
+++ chirp/platform.py
@@ -249,16 +249,6 @@ class UnixPlatform(Platform):
 
         Platform.__init__(self, basepath)
 
-	# This is a hack that needs to be properly fixed by importing the
-	# latest changes to this module from d-rats.  In the interest of
-	# time, however, I'll throw it here
-        if sys.platform == "darwin":
-            if not os.environ.has_key("DISPLAY"):
-                print "Forcing DISPLAY for MacOS"
-                os.environ["DISPLAY"] = ":0"
-
-            os.environ["PANGO_RC_FILE"] = "../Resources/etc/pango/pangorc"
-
     def default_dir(self):
         return os.path.abspath(os.getenv("HOME"))
 
