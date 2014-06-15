$NetBSD: patch-lib_ansible_callbacks.py,v 1.4 2014/06/15 00:15:08 rodent Exp $

Fix hardcoded paths to be replaced with SUBST framework.

--- lib/ansible/callbacks.py.orig	2014-06-09 21:23:31.000000000 +0000
+++ lib/ansible/callbacks.py
@@ -55,9 +55,9 @@ def get_cowsay_info():
         cowsay = "/usr/bin/cowsay"
     elif os.path.exists("/usr/games/cowsay"):
         cowsay = "/usr/games/cowsay"
-    elif os.path.exists("/usr/local/bin/cowsay"):
+    elif os.path.exists("@PREFIX@/bin/cowsay"):
         # BSD path for cowsay
-        cowsay = "/usr/local/bin/cowsay"
+        cowsay = "@PREFIX@/bin/cowsay"
     elif os.path.exists("/opt/local/bin/cowsay"):
         # MacPorts path for cowsay
         cowsay = "/opt/local/bin/cowsay"
