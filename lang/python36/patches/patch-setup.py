$NetBSD: patch-setup.py,v 1.5 2018/06/17 19:21:22 adam Exp $

Disable certain modules, so they can be built as separate packages.
Do not look for ncursesw.
Assume panel_library is correct; this is a fix for ncurses' gnupanel
  which will get transformed to panel in buildlink.

--- setup.py.orig	2018-03-28 09:19:31.000000000 +0000
+++ setup.py
@@ -7,7 +7,7 @@ import importlib._bootstrap
 import importlib.util
 import sysconfig
 
-from distutils import log
+from distutils import log, text_file
 from distutils.errors import *
 from distutils.core import Extension, setup
 from distutils.command.build_ext import build_ext
@@ -43,7 +43,7 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_curses", "_curses_panel", "_elementtree", "_gdbm", "pyexpat", "readline", "_sqlite3", "_tkinter", "xxlimited"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (after any relative
@@ -512,15 +512,15 @@ class PyBuildExt(build_ext):
             return ['m']
 
     def detect_modules(self):
-        # Ensure that /usr/local is always used, but the local build
-        # directories (i.e. '.' and 'Include') must be first.  See issue
-        # 10520.
-        if not cross_compiling:
-            add_dir_to_list(self.compiler.library_dirs, '/usr/local/lib')
-            add_dir_to_list(self.compiler.include_dirs, '/usr/local/include')
-        # only change this for cross builds for 3.3, issues on Mageia
-        if cross_compiling:
-            self.add_gcc_paths()
+        # Add the buildlink directories for pkgsrc
+        if os.environ.get('BUILDLINK_DIR'):
+            dir = os.environ['BUILDLINK_DIR']
+            libdir = dir + '/lib'
+            incdir = dir + '/include'
+            if libdir not in self.compiler.library_dirs:
+                self.compiler.library_dirs.insert(0, libdir)
+            if incdir not in self.compiler.include_dirs:
+                self.compiler.include_dirs.insert(0, incdir)
         self.add_multiarch_paths()
 
         # Add paths specified in the environment variables LDFLAGS and
@@ -776,8 +776,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
         elif self.compiler.find_library_file(lib_dirs, 'curses'):
@@ -842,8 +840,7 @@ class PyBuildExt(build_ext):
                                depends = ['socketmodule.h']) )
         # Detect SSL support for the socket module (via _ssl)
         search_for_ssl_incs_in = [
-                              '/usr/local/ssl/include',
-                              '/usr/contrib/ssl/include/'
+                              '@SSLBASE@/include'
                              ]
         ssl_incs = find_file('openssl/ssl.h', inc_dirs,
                              search_for_ssl_incs_in
@@ -854,9 +851,7 @@ class PyBuildExt(build_ext):
             if krb5_h:
                 ssl_incs += krb5_h
         ssl_libs = find_library_file(self.compiler, 'ssl',lib_dirs,
-                                     ['/usr/local/ssl/lib',
-                                      '/usr/contrib/ssl/lib/'
-                                     ] )
+                                     [] )
 
         if (ssl_incs is not None and
             ssl_libs is not None):
@@ -875,7 +870,7 @@ class PyBuildExt(build_ext):
 
         # look for the openssl version header on the compiler search path.
         opensslv_h = find_file('openssl/opensslv.h', [],
-                inc_dirs + search_for_ssl_incs_in)
+                search_for_ssl_incs_in + inc_dirs)
         if opensslv_h:
             name = os.path.join(opensslv_h[0], 'openssl/opensslv.h')
             if host_platform == 'darwin' and is_macosx_sdk_path(name):
@@ -1275,6 +1270,30 @@ class PyBuildExt(build_ext):
         dbm_order = ['gdbm']
         # The standard Unix dbm module:
         if host_platform not in ['cygwin']:
+
+            ## Top half based on find_file
+            def find_ndbm_h(dirs):
+                ret = None
+                if sys.platform == 'darwin':
+                    sysroot = macosx_sdk_root()
+                for dir in dirs:
+                    f = os.path.join(dir, 'ndbm.h')
+                    if sys.platform == 'darwin' and is_macosx_sdk_path(dir):
+                        f = os.path.join(sysroot, dir[1:], 'ndbm.h')
+                    if not os.path.exists(f): continue
+
+                    ret = 'True'
+                    input = text_file.TextFile(f)
+                    while 1:
+                        line = input.readline()
+                        if not line: break
+                        if re.search('This file is part of GDBM', line):
+                            ret = None
+                            break
+                    input.close()
+                    break
+                return ret
+
             config_args = [arg.strip("'")
                            for arg in sysconfig.get_config_var("CONFIG_ARGS").split()]
             dbm_args = [arg for arg in config_args
@@ -1286,7 +1305,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", inc_dirs, []) is not None:
+                    if find_ndbm_h(inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(lib_dirs,
@@ -1418,8 +1437,7 @@ class PyBuildExt(build_ext):
             missing.append('_curses')
 
         # If the curses module is enabled, check for the panel module
-        if (module_enabled(exts, '_curses') and
-            self.compiler.find_library_file(lib_dirs, panel_library)):
+        if (module_enabled(exts, '_curses')):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
                                    include_dirs=curses_includes,
                                    define_macros=curses_defines,
@@ -2103,10 +2121,7 @@ class PyBuildExt(build_ext):
             depends = ['_decimal/docstrings.h']
         else:
             srcdir = sysconfig.get_config_var('srcdir')
-            include_dirs = [os.path.abspath(os.path.join(srcdir,
-                                                         'Modules',
-                                                         '_decimal',
-                                                         'libmpdec'))]
+            include_dirs = ['Modules/_decimal/libmpdec']
             libraries = self.detect_math_libs()
             sources = [
               '_decimal/_decimal.c',
@@ -2389,7 +2404,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3", "Tools/scripts/pyvenv"]
         )
 
