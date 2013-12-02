$NetBSD: patch-lib_ansible_callbacks.py,v 1.3 2013/12/02 22:54:46 hubertf Exp $

--- lib/ansible/callbacks.py.orig	2013-11-19 19:12:32.000000000 +0000
+++ lib/ansible/callbacks.py
@@ -55,9 +55,9 @@ def get_cowsay_info():
         cowsay = "/usr/bin/cowsay"
     elif os.path.exists("/usr/games/cowsay"):
         cowsay = "/usr/games/cowsay"
-    elif os.path.exists("/usr/local/bin/cowsay"):
+    elif os.path.exists("@LOCALBASE@/bin/cowsay"):
         # BSD path for cowsay
-        cowsay = "/usr/local/bin/cowsay"
+        cowsay = "@LOCALBASE@/bin/cowsay"
     elif os.path.exists("/opt/local/bin/cowsay"):
         # MacPorts path for cowsay
         cowsay = "/opt/local/bin/cowsay"
