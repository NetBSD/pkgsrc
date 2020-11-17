$NetBSD: patch-setup.py,v 1.2 2020/11/17 19:33:26 sjmulder Exp $

Disable certain modules, so they can be built as separate packages.

Do not look for ncursesw.

Assume panel_library is correct; this is a fix for ncurses' gnupanel
which will get transformed to panel in buildlink.

Also look for uuid/uuid.h.

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- setup.py.orig	2020-08-15 05:20:16.000000000 +0000
+++ setup.py
@@ -8,6 +8,7 @@ import importlib.util
 import sysconfig
 
 from distutils import log
+from distutils import text_file
 from distutils.errors import *
 from distutils.core import Extension, setup
 from distutils.command.build_ext import build_ext
@@ -48,7 +49,7 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_curses", "_curses_panel", "_elementtree", "_gdbm", "pyexpat", "readline", "_sqlite3", "_tkinter", "xxlimited"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (after any relative
@@ -150,6 +151,13 @@ def is_macosx_sdk_path(path):
                 or path.startswith('/System/')
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
@@ -581,15 +589,15 @@ class PyBuildExt(build_ext):
             os.unlink(tmpfile)
 
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
@@ -673,6 +681,9 @@ class PyBuildExt(build_ext):
             lib_dirs += ['/usr/lib/hpux64', '/usr/lib/hpux32']
 
         if host_platform == 'darwin':
+            inc_dirs.append(macosx_sdk_root() + '/usr/include')
+            lib_dirs.append(macosx_sdk_root() + '/usr/lib')
+
             # This should work on any unixy platform ;-)
             # If the user has bothered specifying additional -I and -L flags
             # in OPT and LDFLAGS we might as well use them here.
@@ -854,8 +865,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
         elif self.compiler.find_library_file(lib_dirs, 'curses'):
@@ -1285,6 +1294,30 @@ class PyBuildExt(build_ext):
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
@@ -1296,7 +1329,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", inc_dirs, []) is not None:
+                    if find_ndbm_h(inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(lib_dirs,
@@ -1428,8 +1461,7 @@ class PyBuildExt(build_ext):
             missing.append('_curses')
 
         # If the curses module is enabled, check for the panel module
-        if (module_enabled(exts, '_curses') and
-            self.compiler.find_library_file(lib_dirs, panel_library)):
+        if (module_enabled(exts, '_curses')):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
                                    include_dirs=curses_includes,
                                    define_macros=curses_defines,
@@ -1670,6 +1702,8 @@ class PyBuildExt(build_ext):
 
         # Build the _uuid module if possible
         uuid_incs = find_file("uuid.h", inc_dirs, ["/usr/include/uuid"])
+        if uuid_incs is None:
+            uuid_incs = find_file("uuid/uuid.h", inc_dirs, [])
         if uuid_incs is not None:
             if self.compiler.find_library_file(lib_dirs, 'uuid'):
                 uuid_libs = ['uuid']
@@ -1936,43 +1970,15 @@ class PyBuildExt(build_ext):
         # *** Uncomment these for TOGL extension only:
         #       -lGL -lGLU -lXext -lXmu \
 
-    def configure_ctypes_darwin(self, ext):
-        # Darwin (OS X) uses preconfigured files, in
-        # the Modules/_ctypes/libffi_osx directory.
-        srcdir = sysconfig.get_config_var('srcdir')
-        ffi_srcdir = os.path.abspath(os.path.join(srcdir, 'Modules',
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
-            if host_platform == 'darwin':
-                return self.configure_ctypes_darwin(ext)
-            print('INFO: Could not locate ffi libs and/or headers')
-            return False
         return True
 
     def detect_ctypes(self, inc_dirs, lib_dirs):
-        self.use_system_libffi = False
+        if (not sysconfig.get_config_var("LIBFFI_INCLUDEDIR") and host_platform == 'darwin'):
+            self.use_system_libffi = True
+        else:
+            self.use_system_libffi = '--with-system-ffi' in sysconfig.get_config_var("CONFIG_ARGS")
+
         include_dirs = []
         extra_compile_args = []
         extra_link_args = []
@@ -1985,11 +1991,9 @@ class PyBuildExt(build_ext):
 
         if host_platform == 'darwin':
             sources.append('_ctypes/malloc_closure.c')
-            sources.append('_ctypes/darwin/dlfcn_simple.c')
+            extra_compile_args.append('-DUSING_MALLOC_CLOSURE_DOT_C=1')
             extra_compile_args.append('-DMACOSX')
             include_dirs.append('_ctypes/darwin')
-# XXX Is this still needed?
-##            extra_link_args.extend(['-read_only_relocs', 'warning'])
 
         elif host_platform == 'sunos5':
             # XXX This shouldn't be necessary; it appears that some
@@ -2018,30 +2022,48 @@ class PyBuildExt(build_ext):
                      libraries=['m'])
         self.extensions.extend([ext, ext_test])
 
+        ffi_inc = sysconfig.get_config_var("LIBFFI_INCLUDEDIR")
+        ffi_lib = None
+
+        ffi_inc_dirs = inc_dirs.copy()
         if host_platform == 'darwin':
-            if '--with-system-ffi' not in sysconfig.get_config_var("CONFIG_ARGS"):
-                return
-            # OS X 10.5 comes with libffi.dylib; the include files are
-            # in /usr/include/ffi
-            inc_dirs.append('/usr/include/ffi')
-
-        ffi_inc = [sysconfig.get_config_var("LIBFFI_INCLUDEDIR")]
-        if not ffi_inc or ffi_inc[0] == '':
-            ffi_inc = find_file('ffi.h', [], inc_dirs)
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
                 if (self.compiler.find_library_file(lib_dirs, lib_name)):
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
 
@@ -2059,10 +2081,7 @@ class PyBuildExt(build_ext):
             depends = ['_decimal/docstrings.h']
         else:
             srcdir = sysconfig.get_config_var('srcdir')
-            include_dirs = [os.path.abspath(os.path.join(srcdir,
-                                                         'Modules',
-                                                         '_decimal',
-                                                         'libmpdec'))]
+            include_dirs = ['Modules/_decimal/libmpdec']
             libraries = ['m']
             sources = [
               '_decimal/_decimal.c',
@@ -2398,7 +2417,7 @@ def main():
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
+          scripts = ["Tools/scripts/pydoc3",
                      "Tools/scripts/2to3", "Tools/scripts/pyvenv"]
         )
 
