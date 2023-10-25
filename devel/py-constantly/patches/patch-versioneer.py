$NetBSD: patch-versioneer.py,v 1.1 2023/10/25 10:07:36 wiz Exp $

Use Python 3.12 compatible functions.

--- versioneer.py.orig	2015-08-11 08:30:05.000000000 +0000
+++ versioneer.py
@@ -396,9 +396,9 @@ def get_config_from_root(root):
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
