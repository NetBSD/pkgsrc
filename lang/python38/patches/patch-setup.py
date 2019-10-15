$NetBSD: patch-setup.py,v 1.1 2019/10/15 16:50:11 adam Exp $

Disable certain modules, so they can be built as separate packages.
Do not look for ncursesw.
Assume panel_library is correct; this is a fix for ncurses' gnupanel
  which will get transformed to panel in buildlink.
Also look for uuid/uuid.h.

--- setup.py.orig	2019-10-14 13:34:47.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@ import sys
 import sysconfig
 from glob import glob
 
-from distutils import log
+from distutils import log, text_file
 from distutils.command.build_ext import build_ext
 from distutils.command.build_scripts import build_scripts
 from distutils.command.install import install
@@ -24,7 +24,7 @@ from distutils.spawn import find_executa
 TEST_EXTENSIONS = True
 
 # This global variable is used to hold the list of modules to be disabled.
-DISABLED_MODULE_LIST = []
+DISABLED_MODULE_LIST = ["_curses", "_curses_panel", "_elementtree", "_gdbm", "pyexpat", "readline", "_sqlite3", "_tkinter", "xxlimited"]
 
 
 def get_platform():
@@ -645,15 +645,15 @@ class PyBuildExt(build_ext):
                         add_dir_to_list(dir_list, directory)
 
     def configure_compiler(self):
-        # Ensure that /usr/local is always used, but the local build
-        # directories (i.e. '.' and 'Include') must be first.  See issue
-        # 10520.
-        if not CROSS_COMPILING:
-            add_dir_to_list(self.compiler.library_dirs, '/usr/local/lib')
-            add_dir_to_list(self.compiler.include_dirs, '/usr/local/include')
-        # only change this for cross builds for 3.3, issues on Mageia
-        if CROSS_COMPILING:
-            self.add_cross_compiling_paths()
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
         self.add_ldflags_cppflags()
 
@@ -912,8 +912,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         # Issue 36210: OSS provided ncurses does not link on AIX
         # Use IBM supplied 'curses' for successful build of _curses
         elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
@@ -1015,8 +1013,7 @@ class PyBuildExt(build_ext):
         # If the curses module is enabled, check for the panel module
         # _curses_panel needs some form of ncurses
         skip_curses_panel = True if AIX else False
-        if (curses_enabled and not skip_curses_panel and
-                self.compiler.find_library_file(self.lib_dirs, panel_library)):
+        if curses_enabled and not skip_curses_panel:
             self.add(Extension('_curses_panel', ['_curses_panel.c'],
                                include_dirs=curses_includes,
                                define_macros=curses_defines,
@@ -1263,6 +1260,31 @@ class PyBuildExt(build_ext):
         dbm_order = ['gdbm']
         # The standard Unix dbm module:
         if not CYGWIN:
+            # Top half based on find_file
+            def find_ndbm_h(dirs):
+                ret = None
+                if MACOS:
+                    sysroot = macosx_sdk_root()
+                for dir in dirs:
+                    f = os.path.join(dir, 'ndbm.h')
+                    if MACOS and is_macosx_sdk_path(dir):
+                        f = os.path.join(sysroot, dir[1:], 'ndbm.h')
+                    if not os.path.exists(f):
+                        continue
+
+                    ret = True
+                    input = text_file.TextFile(f)
+                    while True:
+                        line = input.readline()
+                        if not line:
+                            break
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
@@ -1274,7 +1296,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", self.inc_dirs, []) is not None:
+                    if find_ndbm_h(self.inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(self.lib_dirs,
@@ -1674,6 +1696,8 @@ class PyBuildExt(build_ext):
     def detect_uuid(self):
         # Build the _uuid module if possible
         uuid_incs = find_file("uuid.h", self.inc_dirs, ["/usr/include/uuid"])
+        if uuid_incs is None:
+            uuid_incs = find_file("uuid/uuid.h", inc_dirs, [])
         if uuid_incs is not None:
             if self.compiler.find_library_file(self.lib_dirs, 'uuid'):
                 uuid_libs = ['uuid']
@@ -2081,10 +2105,7 @@ class PyBuildExt(build_ext):
             sources = ['_decimal/_decimal.c']
             depends = ['_decimal/docstrings.h']
         else:
-            include_dirs = [os.path.abspath(os.path.join(self.srcdir,
-                                                         'Modules',
-                                                         '_decimal',
-                                                         'libmpdec'))]
+            include_dirs = ['Modules/_decimal/libmpdec']
             libraries = ['m']
             sources = [
               '_decimal/_decimal.c',
@@ -2424,7 +2445,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3"]
         )
 
