$NetBSD: patch-versioneer.py,v 1.1 2023/11/05 23:25:31 wiz Exp $

Fix build with Python 3.12.

--- versioneer.py.orig	2020-07-07 09:56:46.000000000 +0000
+++ versioneer.py
@@ -344,9 +344,9 @@ def get_config_from_root(root):
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
