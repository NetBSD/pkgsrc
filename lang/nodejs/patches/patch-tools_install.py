$NetBSD: patch-tools_install.py,v 1.4 2016/01/21 11:45:30 fhajny Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2016-01-21 01:08:27.000000000 +0000
+++ tools/install.py
@@ -141,10 +141,7 @@ def files(action):
 
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
-  else:
-    action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], os.environ.get('PKGMANDIR') + '/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
