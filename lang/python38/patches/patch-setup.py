$NetBSD: patch-setup.py,v 1.4 2020/11/17 19:33:15 sjmulder Exp $

 - Disable certain modules, so they can be built as separate packages.
 - Do not look for ncursesw.
 - Assume panel_library is correct; this is a fix for ncurses' gnupanel
   which will get transformed to panel in buildlink.
 - Also look for uuid/uuid.h.
 - Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
   https://github.com/python/cpython/pull/22855

--- setup.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@ import sys
 import sysconfig
 from glob import glob, escape
 
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
@@ -188,6 +188,13 @@ def is_macosx_sdk_path(path):
                 or path.startswith('/Library/') )
 
 
+def grep_headers_for(function, headers):
+    for header in headers:
+        with open(header, 'r') as f:
+            if function in f.read():
+                return True
+    return False
+
 def find_file(filename, std_dirs, paths):
     """Searches for the directory where a given file is located,
     and returns a possibly-empty list of additional directories, or None
@@ -645,15 +652,15 @@ class PyBuildExt(build_ext):
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
 
@@ -701,6 +708,9 @@ class PyBuildExt(build_ext):
             self.lib_dirs += ['/usr/lib/hpux64', '/usr/lib/hpux32']
 
         if MACOS:
+            self.inc_dirs.append(macosx_sdk_root() + '/usr/include')
+            self.lib_dirs.append(macosx_sdk_root() + '/usr/lib')
+
             # This should work on any unixy platform ;-)
             # If the user has bothered specifying additional -I and -L flags
             # in OPT and LDFLAGS we might as well use them here.
@@ -912,8 +922,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         # Issue 36210: OSS provided ncurses does not link on AIX
         # Use IBM supplied 'curses' for successful build of _curses
         elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
@@ -1015,8 +1023,7 @@ class PyBuildExt(build_ext):
         # If the curses module is enabled, check for the panel module
         # _curses_panel needs some form of ncurses
         skip_curses_panel = True if AIX else False
-        if (curses_enabled and not skip_curses_panel and
-                self.compiler.find_library_file(self.lib_dirs, panel_library)):
+        if curses_enabled and not skip_curses_panel:
             self.add(Extension('_curses_panel', ['_curses_panel.c'],
                                include_dirs=curses_includes,
                                define_macros=curses_defines,
@@ -1263,6 +1270,31 @@ class PyBuildExt(build_ext):
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
@@ -1274,7 +1306,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", self.inc_dirs, []) is not None:
+                    if find_ndbm_h(self.inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(self.lib_dirs,
@@ -1674,6 +1706,8 @@ class PyBuildExt(build_ext):
     def detect_uuid(self):
         # Build the _uuid module if possible
         uuid_incs = find_file("uuid.h", self.inc_dirs, ["/usr/include/uuid"])
+        if uuid_incs is None:
+            uuid_incs = find_file("uuid/uuid.h", self.inc_dirs, [])
         if uuid_incs is not None:
             if self.compiler.find_library_file(self.lib_dirs, 'uuid'):
                 uuid_libs = ['uuid']
@@ -1956,43 +1990,17 @@ class PyBuildExt(build_ext):
                            library_dirs=added_lib_dirs))
         return True
 
-    def configure_ctypes_darwin(self, ext):
-        # Darwin (OS X) uses preconfigured files, in
-        # the Modules/_ctypes/libffi_osx directory.
-        ffi_srcdir = os.path.abspath(os.path.join(self.srcdir, 'Modules',
-                                                  '_ctypes', 'libffi_osx'))
-        sources = [os.path.join(ffi_srcdir, p)
-                   for p in ['ffi.c',
-                             'x86/darwin64.S',
-                             'x86/x86-darwin.S',
-                             'x86/x86-ffi_darwin.c',
-                             'x86/x86-ffi64.c',
-                             'powerpc/ppc-darwin.S',
-                             'powerpc/ppc-darwin_closure.S',
-                             'powerpc/ppc-ffi_darwin.c',
-                             'powerpc/ppc64-darwin_closure.S',
-                             ]]
-
-        # Add .S (preprocessed assembly) to C compiler source extensions.
-        self.compiler.src_extensions.append('.S')
-
-        include_dirs = [os.path.join(ffi_srcdir, 'include'),
-                        os.path.join(ffi_srcdir, 'powerpc')]
-        ext.include_dirs.extend(include_dirs)
-        ext.sources.extend(sources)
-        return True
-
     def configure_ctypes(self, ext):
-        if not self.use_system_libffi:
-            if MACOS:
-                return self.configure_ctypes_darwin(ext)
-            print('INFO: Could not locate ffi libs and/or headers')
-            return False
         return True
 
     def detect_ctypes(self):
         # Thomas Heller's _ctypes module
-        self.use_system_libffi = False
+
+        if (not sysconfig.get_config_var("LIBFFI_INCLUDEDIR") and MACOS):
+            self.use_system_libffi = True
+        else:
+            self.use_system_libffi = '--with-system-ffi' in sysconfig.get_config_var("CONFIG_ARGS")
+
         include_dirs = []
         extra_compile_args = []
         extra_link_args = []
@@ -2005,11 +2013,9 @@ class PyBuildExt(build_ext):
 
         if MACOS:
             sources.append('_ctypes/malloc_closure.c')
-            sources.append('_ctypes/darwin/dlfcn_simple.c')
+            extra_compile_args.append('-DUSING_MALLOC_CLOSURE_DOT_C=1')
             extra_compile_args.append('-DMACOSX')
             include_dirs.append('_ctypes/darwin')
-            # XXX Is this still needed?
-            # extra_link_args.extend(['-read_only_relocs', 'warning'])
 
         elif HOST_PLATFORM == 'sunos5':
             # XXX This shouldn't be necessary; it appears that some
@@ -2039,31 +2045,48 @@ class PyBuildExt(build_ext):
                                sources=['_ctypes/_ctypes_test.c'],
                                libraries=['m']))
 
+        ffi_inc = sysconfig.get_config_var("LIBFFI_INCLUDEDIR")
+        ffi_lib = None
+
         ffi_inc_dirs = self.inc_dirs.copy()
         if MACOS:
-            if '--with-system-ffi' not in sysconfig.get_config_var("CONFIG_ARGS"):
-                return
-            # OS X 10.5 comes with libffi.dylib; the include files are
-            # in /usr/include/ffi
-            ffi_inc_dirs.append('/usr/include/ffi')
-
-        ffi_inc = [sysconfig.get_config_var("LIBFFI_INCLUDEDIR")]
-        if not ffi_inc or ffi_inc[0] == '':
-            ffi_inc = find_file('ffi.h', [], ffi_inc_dirs)
-        if ffi_inc is not None:
-            ffi_h = ffi_inc[0] + '/ffi.h'
+            ffi_in_sdk = os.path.join(macosx_sdk_root(), "usr/include/ffi")
+
+            if not ffi_inc:
+                if os.path.exists(ffi_in_sdk):
+                    ext.extra_compile_args.append("-DUSING_APPLE_OS_LIBFFI=1")
+                    ffi_inc = ffi_in_sdk
+                    ffi_lib = 'ffi'
+                else:
+                    # OS X 10.5 comes with libffi.dylib; the include files are
+                    # in /usr/include/ffi
+                    ffi_inc_dirs.append('/usr/include/ffi')
+
+        if not ffi_inc:
+            found = find_file('ffi.h', [], ffi_inc_dirs)
+            if found:
+                ffi_inc = found[0]
+        if ffi_inc:
+            ffi_h = ffi_inc + '/ffi.h'
             if not os.path.exists(ffi_h):
                 ffi_inc = None
                 print('Header file {} does not exist'.format(ffi_h))
-        ffi_lib = None
-        if ffi_inc is not None:
+        if ffi_lib is None and ffi_inc:
             for lib_name in ('ffi', 'ffi_pic'):
                 if (self.compiler.find_library_file(self.lib_dirs, lib_name)):
                     ffi_lib = lib_name
                     break
 
         if ffi_inc and ffi_lib:
-            ext.include_dirs.extend(ffi_inc)
+            ffi_headers = glob(os.path.join(ffi_inc, '*.h'))
+            if grep_headers_for('ffi_prep_cif_var', ffi_headers):
+                ext.extra_compile_args.append("-DHAVE_FFI_PREP_CIF_VAR=1")
+            if grep_headers_for('ffi_prep_closure_loc', ffi_headers):
+                ext.extra_compile_args.append("-DHAVE_FFI_PREP_CLOSURE_LOC=1")
+            if grep_headers_for('ffi_closure_alloc', ffi_headers):
+                ext.extra_compile_args.append("-DHAVE_FFI_CLOSURE_ALLOC=1")
+
+            ext.include_dirs.append(ffi_inc)
             ext.libraries.append(ffi_lib)
             self.use_system_libffi = True
 
@@ -2081,10 +2104,7 @@ class PyBuildExt(build_ext):
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
@@ -2424,7 +2444,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3"]
         )
 
