$NetBSD: patch-Lib_distutils_sysconfig.py,v 1.1 2019/10/15 16:50:11 adam Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- Lib/distutils/sysconfig.py.orig	2016-12-23 02:21:19.000000000 +0000
+++ Lib/distutils/sysconfig.py
@@ -242,8 +242,6 @@ def get_makefile_filename():
         return os.path.join(_sys_home or project_base, "Makefile")
     lib_dir = get_python_lib(plat_specific=0, standard_lib=1)
     config_file = 'config-{}{}'.format(get_python_version(), build_flags)
-    if hasattr(sys.implementation, '_multiarch'):
-        config_file += '-%s' % sys.implementation._multiarch
     return os.path.join(lib_dir, config_file, 'Makefile')
 
 
@@ -419,10 +417,8 @@ def _init_posix():
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
