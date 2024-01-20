$NetBSD: patch-versioneer.py,v 1.1 2024/01/20 16:10:37 wiz Exp $

Adapt for deprecations.

--- versioneer.py.orig	2024-01-20 16:09:08.157756624 +0000
+++ versioneer.py
@@ -339,9 +339,9 @@ def get_config_from_root(root):
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
