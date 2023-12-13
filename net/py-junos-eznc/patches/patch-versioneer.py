$NetBSD: patch-versioneer.py,v 1.1 2023/12/13 19:21:35 wiz Exp $

Update for API changes.

--- versioneer.py.orig	2023-12-13 19:20:26.943244642 +0000
+++ versioneer.py
@@ -343,9 +343,9 @@ def get_config_from_root(root):
     # configparser.NoOptionError (if it lacks "VCS="). See the docstring at
     # the top of versioneer.py for instructions on writing your setup.cfg .
     setup_cfg = os.path.join(root, "setup.cfg")
-    parser = configparser.SafeConfigParser()
+    parser = configparser.ConfigParser()
     with open(setup_cfg, "r") as f:
-        parser.readfp(f)
+        parser.read_file(f)
     VCS = parser.get("versioneer", "VCS")  # mandatory
 
     def get(parser, name):
