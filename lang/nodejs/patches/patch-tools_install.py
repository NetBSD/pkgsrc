$NetBSD: patch-tools_install.py,v 1.5 2017/04/12 11:26:52 fhajny Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2017-04-11 15:48:50.000000000 +0000
+++ tools/install.py
@@ -136,10 +136,7 @@ def files(action):
   action(['deps/v8/tools/lldbinit'], 'share/doc/node/')
   action(['deps/v8/tools/lldb_commands.py'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
-  else:
-    action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], os.environ.get('PKGMANDIR') + '/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
