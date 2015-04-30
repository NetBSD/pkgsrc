$NetBSD: patch-tools_install.py,v 1.2 2015/04/30 15:04:56 ryoon Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2015-03-31 22:13:01.000000000 +0000
+++ tools/install.py
@@ -136,9 +136,9 @@ def files(action):
   action(['src/node.stp'], 'share/systemtap/tapset/')
 
   if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
