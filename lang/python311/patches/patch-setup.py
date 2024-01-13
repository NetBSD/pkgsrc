$NetBSD: patch-setup.py,v 1.3 2024/01/13 04:24:28 riastradh Exp $

Disable certain modules, so they can be built as separate packages.
Do not look for ncursesw.
Assume panel_library is correct; this is a fix for ncurses' gnupanel
which will get transformed to panel in buildlink.
Don't search for modules in PREFIX. Fixes build failure when py-setuptools
  are installed.
Enable cross-build by setting sys._home and sys.path to build directory
Module _crypt might need -lcrypt (taken from Python 3.10).
Disable circuitous readline detection which tries to outsmart pkgsrc's
static choice of libreadline and (fake-)ncurses and trips over its elven
shoelaces when cross-compiling.

--- setup.py.orig	2023-12-04 17:56:29.000000000 +0000
+++ setup.py
@@ -1,5 +1,11 @@
 # Autodetecting setup.py script for building the Python extensions
 
+import sys
+sys._home = __file__[:-len('/setup.py')]
+sys.path.append(__file__[:-len('/setup.py')] + '/Lib')
+with open('pybuilddir.txt') as pybuilddir:
+    sys.path.append(__file__[:-len('/setup.py')] + '/' + next(pybuilddir))
+
 import argparse
 import importlib._bootstrap
 import importlib.machinery
@@ -14,6 +20,7 @@ import warnings
 from glob import glob, escape
 import _osx_support
 
+sys.path = [p for p in sys.path if not re.compile('^' + sys.base_prefix + '/lib').match(p)]
 
 try:
     import subprocess
@@ -46,6 +53,7 @@ with warnings.catch_warnings():
         DeprecationWarning
     )
 
+    from distutils import text_file
     from distutils.command.build_ext import build_ext
     from distutils.command.build_scripts import build_scripts
     from distutils.command.install import install
@@ -56,7 +64,7 @@ with warnings.catch_warnings():
 
 
 # This global variable is used to hold the list of modules to be disabled.
-DISABLED_MODULE_LIST = []
+DISABLED_MODULE_LIST = ["_gdbm", "_tkinter", "xxlimited"]
 
 # --list-module-names option used by Tools/scripts/generate_module_names.py
 LIST_MODULE_NAMES = False
@@ -230,6 +238,16 @@ def grep_headers_for(function, headers):
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
@@ -843,15 +861,15 @@ class PyBuildExt(build_ext):
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
 
@@ -899,6 +917,9 @@ class PyBuildExt(build_ext):
             self.lib_dirs += ['/usr/lib/hpux64', '/usr/lib/hpux32']
 
         if MACOS:
+            self.inc_dirs.append(macosx_sdk_root() + '/usr/include')
+            self.lib_dirs.append(macosx_sdk_root() + '/usr/lib')
+
             # This should work on any unixy platform ;-)
             # If the user has bothered specifying additional -I and -L flags
             # in OPT and LDFLAGS we might as well use them here.
@@ -1036,71 +1057,10 @@ class PyBuildExt(build_ext):
     def detect_readline_curses(self):
         # readline
         readline_termcap_library = ""
-        curses_library = ""
-        # Cannot use os.popen here in py3k.
-        tmpfile = os.path.join(self.build_temp, 'readline_termcap_lib')
-        if not os.path.exists(self.build_temp):
-            os.makedirs(self.build_temp)
-        # Determine if readline is already linked against curses or tinfo.
-        if sysconfig.get_config_var('HAVE_LIBREADLINE'):
-            if sysconfig.get_config_var('WITH_EDITLINE'):
-                readline_lib = 'edit'
-            else:
-                readline_lib = 'readline'
-            do_readline = self.compiler.find_library_file(self.lib_dirs,
-                readline_lib)
-            if CROSS_COMPILING:
-                ret = run_command("%s -d %s | grep '(NEEDED)' > %s"
-                                % (sysconfig.get_config_var('READELF'),
-                                   do_readline, tmpfile))
-            elif find_executable('ldd'):
-                ret = run_command("ldd %s > %s" % (do_readline, tmpfile))
-            else:
-                ret = 1
-            if ret == 0:
-                with open(tmpfile) as fp:
-                    for ln in fp:
-                        if 'curses' in ln:
-                            readline_termcap_library = re.sub(
-                                r'.*lib(n?cursesw?)\.so.*', r'\1', ln
-                            ).rstrip()
-                            break
-                        # termcap interface split out from ncurses
-                        if 'tinfo' in ln:
-                            readline_termcap_library = 'tinfo'
-                            break
-            if os.path.exists(tmpfile):
-                os.unlink(tmpfile)
-        else:
-            do_readline = False
-        # Issue 7384: If readline is already linked against curses,
-        # use the same library for the readline and curses modules.
-        if 'curses' in readline_termcap_library:
-            curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
-        # Issue 36210: OSS provided ncurses does not link on AIX
-        # Use IBM supplied 'curses' for successful build of _curses
-        elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
-            curses_library = 'curses'
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncurses'):
-            curses_library = 'ncurses'
-        elif self.compiler.find_library_file(self.lib_dirs, 'curses'):
-            curses_library = 'curses'
+        curses_library = "ncurses"
+        do_readline = True
+        readline_lib = 'readline'
 
-        if MACOS:
-            os_release = int(os.uname()[2].split('.')[0])
-            dep_target = sysconfig.get_config_var('MACOSX_DEPLOYMENT_TARGET')
-            if (dep_target and
-                    (tuple(int(n) for n in dep_target.split('.')[0:2])
-                        < (10, 5) ) ):
-                os_release = 8
-            if os_release < 9:
-                # MacOSX 10.4 has a broken readline. Don't try to build
-                # the readline module unless the user has installed a fixed
-                # readline package
-                if find_file('readline/rlconf.h', self.inc_dirs, []) is None:
-                    do_readline = False
         if do_readline:
             readline_libs = [readline_lib]
             if readline_termcap_library:
@@ -1169,8 +1129,7 @@ class PyBuildExt(build_ext):
         # If the curses module is enabled, check for the panel module
         # _curses_panel needs some form of ncurses
         skip_curses_panel = True if AIX else False
-        if (curses_enabled and not skip_curses_panel and
-                self.compiler.find_library_file(self.lib_dirs, panel_library)):
+        if curses_enabled and not skip_curses_panel:
             self.add(Extension('_curses_panel', ['_curses_panel.c'],
                            include_dirs=curses_includes,
                            define_macros=curses_defines,
@@ -1179,7 +1138,11 @@ class PyBuildExt(build_ext):
             self.missing.append('_curses_panel')
 
     def detect_crypt(self):
-        self.addext(Extension('_crypt', ['_cryptmodule.c']))
+        if self.compiler.find_library_file(self.lib_dirs, 'crypt'):
+            libs = ['crypt']
+        else:
+            libs = []
+        self.addext(Extension('_crypt', ['_cryptmodule.c'], libraries=libs))
 
     def detect_dbm_gdbm(self):
         # Modules that provide persistent dictionary-like semantics.  You will
@@ -1202,6 +1165,31 @@ class PyBuildExt(build_ext):
 
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
@@ -1619,7 +1607,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3"]
         )
 
