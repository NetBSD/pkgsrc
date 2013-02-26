$NetBSD: patch-lib_ansible_constants.py,v 1.1 2013/02/26 00:13:00 hubertf Exp $

diff --git a/lib/ansible/constants.py b/lib/ansible/constants.py
index b43986e..2e60046 100644
--- lib/ansible/constants.py
+++ lib/ansible/constants.py
@@ -65,6 +65,8 @@ if getattr(sys, "real_prefix", None):
     DIST_MODULE_PATH = os.path.join(sys.prefix, 'share/ansible/')
 else:
     DIST_MODULE_PATH = '/usr/share/ansible/'
+    # HF: work as non-root with python install --prefix=...
+    DIST_MODULE_PATH = '@PREFIX@/share/ansible/'			
 
 # sections in config file
 DEFAULTS='defaults'
