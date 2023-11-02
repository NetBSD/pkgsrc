$NetBSD: patch-tools_install.py,v 1.1 2023/11/02 13:16:54 adam Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2021-09-10 17:25:14.000000000 +0000
+++ tools/install.py
@@ -156,10 +156,7 @@ def files(action):
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
   action(['deps/v8/tools/lldb_commands.py'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
-    action(['doc/node.1'], 'man/man1/')
-  else:
-    action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], os.environ.get('PKGMANDIR') + '/man1/')
 
   if 'true' == variables.get('node_install_npm'):
     npm_files(action)
