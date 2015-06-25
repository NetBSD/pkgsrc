$NetBSD: patch-lib_ansible_callbacks.py,v 1.5 2015/06/25 13:21:03 jperkin Exp $

Fix hardcoded paths to be replaced with SUBST framework.

--- lib/ansible/callbacks.py.orig	2014-07-25 20:48:49.000000000 +0000
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
