$NetBSD: patch-Lib_sysconfig_____init____.py,v 1.1 2024/10/09 19:53:20 adam Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- Lib/sysconfig/__init__.py.orig	2024-10-07 05:02:14.000000000 +0000
+++ Lib/sysconfig/__init__.py
@@ -324,16 +324,13 @@ def get_makefile_filename():
         config_dir_name = f'config-{_PY_VERSION_SHORT}{sys.abiflags}'
     else:
         config_dir_name = 'config'
-    if hasattr(sys.implementation, '_multiarch'):
-        config_dir_name += f'-{sys.implementation._multiarch}'
     return os.path.join(get_path('stdlib'), config_dir_name, 'Makefile')
 
 
 def _get_sysconfigdata_name():
-    multiarch = getattr(sys.implementation, '_multiarch', '')
     return os.environ.get(
         '_PYTHON_SYSCONFIGDATA_NAME',
-        f'_sysconfigdata_{sys.abiflags}_{sys.platform}_{multiarch}',
+        f'_sysconfigdata_{sys.platform}',
     )
 
 def _init_posix(vars):
