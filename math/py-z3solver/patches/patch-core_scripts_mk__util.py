$NetBSD: patch-core_scripts_mk__util.py,v 1.3 2022/05/09 09:08:27 jperkin Exp $

Try to at least use sensible defaults on unknown platforms.

--- core/scripts/mk_util.py.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/scripts/mk_util.py
@@ -1263,8 +1263,7 @@ def get_so_ext():
     elif sysname == 'CYGWIN' or sysname.startswith('MSYS_NT') or sysname.startswith('MINGW'):
         return 'dll'
     else:
-        assert(False)
-        return 'dll'
+        return 'so'
 
 class DLLComponent(Component):
     def __init__(self, name, dll_name, path, deps, export_files, reexports, install, static, staging_link=None):
@@ -2527,7 +2526,8 @@ def mk_config():
             EXE_EXT        = '.exe'
             LIB_EXT        = '.lib'
         else:
-            raise MKException('Unsupported platform: %s' % sysname)
+            SO_EXT         = '.so'
+            SLIBFLAGS      = '-shared'
         if is64():
             if not sysname.startswith('CYGWIN') and not sysname.startswith('MSYS') and not sysname.startswith('MINGW'):
                 CXXFLAGS     = '%s -fPIC' % CXXFLAGS
