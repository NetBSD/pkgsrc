$NetBSD: patch-tools_install.py,v 1.3 2015/09/09 00:04:54 ryoon Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2015-09-08 15:30:49.000000000 +0000
+++ tools/install.py
@@ -141,9 +141,9 @@ def files(action):
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
 
   if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
