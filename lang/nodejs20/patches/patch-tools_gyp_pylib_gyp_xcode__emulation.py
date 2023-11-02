$NetBSD: patch-tools_gyp_pylib_gyp_xcode__emulation.py,v 1.1 2023/11/02 13:16:54 adam Exp $

Do not generate debugging symbols (uses lots of disk space).

--- tools/gyp/pylib/gyp/xcode_emulation.py.orig	2020-10-07 17:47:43.000000000 +0000
+++ tools/gyp/pylib/gyp/xcode_emulation.py
@@ -610,7 +610,7 @@ class XcodeSettings(object):
 
         self._Appendf(cflags, "GCC_OPTIMIZATION_LEVEL", "-O%s", default="s")
 
-        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES"):
+        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO"):
             dbg_format = self._Settings().get("DEBUG_INFORMATION_FORMAT", "dwarf")
             if dbg_format == "dwarf":
                 cflags.append("-gdwarf-2")
@@ -1097,7 +1097,7 @@ class XcodeSettings(object):
         # For static libraries, no dSYMs are created.
         result = []
         if (
-            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES")
+            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO")
             and self._Test(
                 "DEBUG_INFORMATION_FORMAT", "dwarf-with-dsym", default="dwarf"
             )
