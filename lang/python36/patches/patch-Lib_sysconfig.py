$NetBSD: patch-Lib_sysconfig.py,v 1.1 2017/01/01 14:34:27 adam Exp $

Simplify _sysconfigdata to include only platform name.

--- Lib/sysconfig.py.orig	2017-01-01 13:52:46.000000000 +0000
+++ Lib/sysconfig.py
@@ -344,10 +344,8 @@ def get_makefile_filename():
 
 def _get_sysconfigdata_name():
     return os.environ.get('_PYTHON_SYSCONFIGDATA_NAME',
-        '_sysconfigdata_{abi}_{platform}_{multiarch}'.format(
-        abi=sys.abiflags,
+        '_sysconfigdata_{platform}'.format(
         platform=sys.platform,
-        multiarch=getattr(sys.implementation, '_multiarch', ''),
     ))
 
 
