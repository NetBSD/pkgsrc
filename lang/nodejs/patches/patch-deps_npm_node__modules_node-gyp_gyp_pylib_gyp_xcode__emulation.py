$NetBSD: patch-deps_npm_node__modules_node-gyp_gyp_pylib_gyp_xcode__emulation.py,v 1.1 2017/05/30 14:26:38 adam Exp $

Do not generate debugging symbols (uses lots of disk space).

--- deps/npm/node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py.orig	2017-05-30 13:51:50.000000000 +0000
+++ deps/npm/node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py
@@ -500,7 +500,7 @@ class XcodeSettings(object):
 
     self._Appendf(cflags, 'GCC_OPTIMIZATION_LEVEL', '-O%s', default='s')
 
-    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='YES'):
+    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='NO'):
       dbg_format = self._Settings().get('DEBUG_INFORMATION_FORMAT', 'dwarf')
       if dbg_format == 'dwarf':
         cflags.append('-gdwarf-2')
