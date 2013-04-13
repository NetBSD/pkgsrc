$NetBSD: patch-lib_ansible_callbacks.py,v 1.2 2013/04/13 17:51:57 riz Exp $

--- lib/ansible/callbacks.py.orig	2013-03-30 16:29:28.000000000 -0700
+++ lib/ansible/callbacks.py	2013-04-13 09:05:36.000000000 -0700
@@ -30,9 +30,9 @@
     cowsay = "/usr/bin/cowsay"
 elif os.path.exists("/usr/games/cowsay"):
     cowsay = "/usr/games/cowsay"
-elif os.path.exists("/usr/local/bin/cowsay"):
+elif os.path.exists("@LOCALBASE@/bin/cowsay"):
     # BSD path for cowsay
-    cowsay = "/usr/local/bin/cowsay"
+    cowsay = "@LOCALBASE@/bin/cowsay"
 elif os.path.exists("/opt/local/bin/cowsay"):
     # MacPorts path for cowsay
     cowsay = "/opt/local/bin/cowsay"
