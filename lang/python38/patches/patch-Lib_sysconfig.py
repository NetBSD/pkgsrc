$NetBSD: patch-Lib_sysconfig.py,v 1.1 2019/10/15 16:50:11 adam Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- Lib/sysconfig.py.orig	2016-12-23 02:21:19.000000000 +0000
+++ Lib/sysconfig.py
@@ -337,17 +337,13 @@ def get_makefile_filename():
         config_dir_name = 'config-%s%s' % (_PY_VERSION_SHORT, sys.abiflags)
     else:
         config_dir_name = 'config'
-    if hasattr(sys.implementation, '_multiarch'):
-        config_dir_name += '-%s' % sys.implementation._multiarch
     return os.path.join(get_path('stdlib'), config_dir_name, 'Makefile')
 
 
 def _get_sysconfigdata_name():
     return os.environ.get('_PYTHON_SYSCONFIGDATA_NAME',
-        '_sysconfigdata_{abi}_{platform}_{multiarch}'.format(
-        abi=sys.abiflags,
+        '_sysconfigdata_{platform}'.format(
         platform=sys.platform,
-        multiarch=getattr(sys.implementation, '_multiarch', ''),
     ))
 
 
