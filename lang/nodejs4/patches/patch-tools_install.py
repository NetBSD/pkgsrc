$NetBSD: patch-tools_install.py,v 1.2 2016/01/21 11:43:44 fhajny Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2016-01-20 19:09:38.000000000 +0000
+++ tools/install.py
@@ -140,10 +140,7 @@ def files(action):
 
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
-  else:
-    action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], os.environ.get('PKGMANDIR') + '/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
