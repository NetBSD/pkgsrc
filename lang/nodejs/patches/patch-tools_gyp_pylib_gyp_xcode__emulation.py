$NetBSD: patch-tools_gyp_pylib_gyp_xcode__emulation.py,v 1.1 2017/05/30 14:26:38 adam Exp $

Do not generate debugging symbols (uses lots of disk space).

--- tools/gyp/pylib/gyp/xcode_emulation.py.orig	2017-05-30 14:15:04.000000000 +0000
+++ tools/gyp/pylib/gyp/xcode_emulation.py
@@ -577,7 +577,7 @@ class XcodeSettings(object):
 
     self._Appendf(cflags, 'GCC_OPTIMIZATION_LEVEL', '-O%s', default='s')
 
-    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='YES'):
+    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='NO'):
       dbg_format = self._Settings().get('DEBUG_INFORMATION_FORMAT', 'dwarf')
       if dbg_format == 'dwarf':
         cflags.append('-gdwarf-2')
