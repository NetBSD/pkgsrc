$NetBSD: patch-Lib_sysconfig_____init____.py,v 1.1 2025/10/08 07:13:08 adam Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- Lib/sysconfig/__init__.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/sysconfig/__init__.py
@@ -338,8 +338,6 @@ def get_makefile_filename():
     else:
         config_dir_name = 'config'
 
-    if hasattr(sys.implementation, '_multiarch'):
-        config_dir_name += f'-{sys.implementation._multiarch}'
 
     return os.path.join(get_path('stdlib'), config_dir_name, 'Makefile')
 
@@ -357,10 +355,9 @@ def _import_from_directory(path, name):
 
 
 def _get_sysconfigdata_name():
-    multiarch = getattr(sys.implementation, '_multiarch', '')
     return os.environ.get(
         '_PYTHON_SYSCONFIGDATA_NAME',
-        f'_sysconfigdata_{sys.abiflags}_{sys.platform}_{multiarch}',
+        f'_sysconfigdata_{sys.platform}',
     )
 
 
