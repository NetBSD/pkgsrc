$NetBSD: patch-Lib_sysconfig.py,v 1.1 2023/10/02 20:07:15 adam Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- Lib/sysconfig.py.orig	2021-07-10 00:51:07.000000000 +0000
+++ Lib/sysconfig.py
@@ -394,16 +394,13 @@ def get_makefile_filename():
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
 
 
