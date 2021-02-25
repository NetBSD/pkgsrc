$NetBSD: patch-bindings_python_unicorn_unicorn.py,v 1.2 2021/02/25 19:47:51 leot Exp $

--- bindings/python/unicorn/unicorn.py.orig	2020-10-21 11:34:41.000000000 +0000
+++ bindings/python/unicorn/unicorn.py
@@ -71,20 +71,9 @@ def _load_lib(path):
 _uc = None
 
 # Loading attempts, in order
-# - user-provided environment variable
-# - pkg_resources can get us the path to the local libraries
-# - we can get the path to the local libraries by parsing our filename
-# - global load
-# - python's lib directory
-# - last-gasp attempt at some hardcoded paths on darwin and linux
-
-_path_list = [os.getenv('LIBUNICORN_PATH', None),
-              pkg_resources.resource_filename(__name__, 'lib'),
-              os.path.join(os.path.split(__file__)[0], 'lib'),
-              '',
-              distutils.sysconfig.get_python_lib(),
-              "/usr/local/lib/" if sys.platform == 'darwin' else '/usr/lib64',
-              os.getenv('PATH', '')]
+# - Python installation prefix / lib
+
+_path_list = [os.path.join(sys.prefix, 'lib')]
 
 #print(_path_list)
 #print("-" * 80)
