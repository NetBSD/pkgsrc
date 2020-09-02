$NetBSD: patch-setuptools___distutils_sysconfig.py,v 1.1 2020/09/02 21:42:18 wiz Exp $

Remove _multiarch from config path (differs across platforms).
Simplify _sysconfigdata to include only platform name.

--- setuptools/_distutils/sysconfig.py.orig	2020-09-01 17:50:24.000000000 +0000
+++ setuptools/_distutils/sysconfig.py
@@ -274,8 +274,6 @@ def get_makefile_filename():
         return os.path.join(_sys_home or project_base, "Makefile")
     lib_dir = get_python_lib(plat_specific=0, standard_lib=1)
     config_file = 'config-{}{}'.format(get_python_version(), build_flags)
-    if hasattr(sys.implementation, '_multiarch'):
-        config_file += '-%s' % sys.implementation._multiarch
     return os.path.join(lib_dir, config_file, 'Makefile')
 
 
@@ -451,10 +449,8 @@ def _init_posix():
     """Initialize the module as appropriate for POSIX systems."""
     # _sysconfigdata is generated at build time, see the sysconfig module
     name = os.environ.get('_PYTHON_SYSCONFIGDATA_NAME',
-        '_sysconfigdata_{abi}_{platform}_{multiarch}'.format(
-        abi=sys.abiflags,
+        '_sysconfigdata_{platform}'.format(
         platform=sys.platform,
-        multiarch=getattr(sys.implementation, '_multiarch', ''),
     ))
     try:
         _temp = __import__(name, globals(), locals(), ['build_time_vars'], 0)
