$NetBSD: patch-lib_ansible_callbacks.py,v 1.1 2013/02/26 00:13:00 hubertf Exp $

--- lib/ansible/callbacks.py.orig	2013-01-26 16:50:21.000000000 +0000
+++ lib/ansible/callbacks.py
@@ -31,9 +31,9 @@ elif os.path.exists("/usr/bin/cowsay"):
     cowsay = "/usr/bin/cowsay"
 elif os.path.exists("/usr/games/cowsay"):
     cowsay = "/usr/games/cowsay"
-elif os.path.exists("/usr/local/bin/cowsay"):
+elif os.path.exists("@LOCALBASE@/bin/cowsay"):
     # BSD path for cowsay
-    cowsay = "/usr/local/bin/cowsay"
+    cowsay = "@LOCALBASE@/bin/cowsay"
 
 def call_callback_module(method_name, *args, **kwargs):
 
