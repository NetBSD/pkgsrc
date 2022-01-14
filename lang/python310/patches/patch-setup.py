$NetBSD: patch-setup.py,v 1.4 2022/01/14 10:32:28 tnn Exp $

Disable certain modules, so they can be built as separate packages.
Do not look for ncursesw.
Assume panel_library is correct; this is a fix for ncurses' gnupanel
which will get transformed to panel in buildlink.
Don't search for modules in PREFIX. Fixes build failure when py-setuptools
  are installed.  

--- setup.py.orig	2021-12-06 18:23:39.000000000 +0000
+++ setup.py
@@ -13,6 +13,7 @@ import warnings
 from glob import glob, escape
 import _osx_support
 
+sys.path = [p for p in sys.path if not re.compile('^' + sys.base_prefix + '/').match(p)]
 
 try:
     import subprocess
@@ -45,6 +46,7 @@ with warnings.catch_warnings():
         DeprecationWarning
     )
 
+    from distutils import text_file
     from distutils.command.build_ext import build_ext
     from distutils.command.build_scripts import build_scripts
     from distutils.command.install import install
@@ -58,7 +60,7 @@ with warnings.catch_warnings():
 TEST_EXTENSIONS = (sysconfig.get_config_var('TEST_MODULES') == 'yes')
 
 # This global variable is used to hold the list of modules to be disabled.
-DISABLED_MODULE_LIST = []
+DISABLED_MODULE_LIST = ["_curses", "_curses_panel", "_elementtree", "_gdbm", "pyexpat", "readline", "_sqlite3", "_tkinter", "xxlimited"]
 
 # --list-module-names option used by Tools/scripts/generate_module_names.py
 LIST_MODULE_NAMES = False
@@ -249,6 +251,16 @@ def grep_headers_for(function, headers):
     return False
 
 
+def grep_headers_for(function, headers):
+    for header in headers:
+        try:
+            with open(header, 'r') as f:
+                if function in f.read():
+                    return True
+        except UnicodeDecodeError:
+            pass
+    return False
+
 def find_file(filename, std_dirs, paths):
     """Searches for the directory where a given file is located,
     and returns a possibly-empty list of additional directories, or None
@@ -821,15 +833,15 @@ class PyBuildExt(build_ext):
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
 
@@ -877,6 +889,9 @@ class PyBuildExt(build_ext):
             self.lib_dirs += ['/usr/lib/hpux64', '/usr/lib/hpux32']
 
         if MACOS:
+            self.inc_dirs.append(macosx_sdk_root() + '/usr/include')
+            self.lib_dirs.append(macosx_sdk_root() + '/usr/lib')
+
             # This should work on any unixy platform ;-)
             # If the user has bothered specifying additional -I and -L flags
             # in OPT and LDFLAGS we might as well use them here.
@@ -1104,8 +1119,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         # Issue 36210: OSS provided ncurses does not link on AIX
         # Use IBM supplied 'curses' for successful build of _curses
         elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
@@ -1209,8 +1222,7 @@ class PyBuildExt(build_ext):
         # If the curses module is enabled, check for the panel module
         # _curses_panel needs some form of ncurses
         skip_curses_panel = True if AIX else False
-        if (curses_enabled and not skip_curses_panel and
-                self.compiler.find_library_file(self.lib_dirs, panel_library)):
+        if curses_enabled and not skip_curses_panel:
             self.add(Extension('_curses_panel', ['_curses_panel.c'],
                            include_dirs=curses_includes,
                            define_macros=curses_defines,
@@ -1455,6 +1467,31 @@ class PyBuildExt(build_ext):
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
@@ -1466,7 +1503,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", self.inc_dirs, []) is not None:
+                    if find_ndbm_h(self.inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(self.lib_dirs,
@@ -2326,10 +2363,7 @@ class PyBuildExt(build_ext):
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
@@ -2745,7 +2779,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3"]
         )
 
