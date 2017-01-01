$NetBSD: patch-Lib_distutils_sysconfig.py,v 1.1 2017/01/01 14:34:27 adam Exp $

Simplify _sysconfigdata to include only platform name.

--- Lib/distutils/sysconfig.py.orig	2017-01-01 13:54:39.000000000 +0000
+++ Lib/distutils/sysconfig.py
@@ -419,10 +419,8 @@ def _init_posix():
     """Initialize the module as appropriate for POSIX systems."""
     # _sysconfigdata is generated at build time, see the sysconfig module
     name = os.environ.get('_PYTHON_SYSCONFIGDATA_NAME',
-        '_sysconfigdata_{abi}_{platform}_{multiarch}'.format(
-        abi=sys.abiflags,
+        '_sysconfigdata_{platform}'.format(
         platform=sys.platform,
-        multiarch=getattr(sys.implementation, '_multiarch', ''),
     ))
     _temp = __import__(name, globals(), locals(), ['build_time_vars'], 0)
     build_time_vars = _temp.build_time_vars
