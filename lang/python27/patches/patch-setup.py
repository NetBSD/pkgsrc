$NetBSD: patch-setup.py,v 1.4 2023/10/23 06:36:00 wiz Exp $

Disable certain modules, so they can be built as separate packages.
Only check the BUILDLINK_DIR for libraries etc, do not pick up random
headers and libraries from the system.

Do not look for ncursesw.
Assume panel_library is correct; this is a fix for ncurses' gnupanel
  which will get transformed to panel in buildlink.

Build the _ssl module with pkgsrc choiced OpenSSL.  Support OpenSSL 3.x

macOS arm64 support, via MacPorts.

cygwin 2.7.3-no-libm.patch

--- setup.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ setup.py
@@ -16,6 +16,7 @@ from distutils.command.build_ext import
 from distutils.command.install import install
 from distutils.command.install_lib import install_lib
 from distutils.spawn import find_executable
+import distutils.command.config
 
 cross_compiling = "_PYTHON_HOST_PLATFORM" in os.environ
 
@@ -33,7 +34,7 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "bsddb185", "gdbm", "_tkinter", "linuxaudiodev", "ossaudiodev", "sunaudiodev"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -500,10 +501,15 @@ class PyBuildExt(build_ext):
             os.unlink(tmpfile)
 
     def detect_modules(self):
-        # Ensure that /usr/local is always used
-        if not cross_compiling:
-            add_dir_to_list(self.compiler.library_dirs, '/usr/local/lib')
-            add_dir_to_list(self.compiler.include_dirs, '/usr/local/include')
+        # Add the buildlink directories for pkgsrc
+        if os.environ.has_key('BUILDLINK_DIR'):
+            dir = os.environ['BUILDLINK_DIR']
+            libdir = dir + '/lib'
+            incdir = dir + '/include'
+            if libdir not in self.compiler.library_dirs:
+                self.compiler.library_dirs.insert(0, libdir)
+            if incdir not in self.compiler.include_dirs:
+                self.compiler.include_dirs.insert(0, incdir)
         if cross_compiling:
             self.add_gcc_paths()
         self.add_multiarch_paths()
@@ -615,7 +621,7 @@ class PyBuildExt(build_ext):
 
         # Check for MacOS X, which doesn't need libm.a at all
         math_libs = ['m']
-        if host_platform in ['darwin', 'beos']:
+        if host_platform in ['darwin', 'beos', 'cygwin']:
             math_libs = []
 
         # XXX Omitted modules: gl, pure, dl, SGI-specific modules
@@ -791,8 +797,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
         elif self.compiler.find_library_file(lib_dirs, 'curses'):
@@ -855,11 +859,10 @@ class PyBuildExt(build_ext):
                                libraries=math_libs) )
         # Detect SSL support for the socket module (via _ssl)
         search_for_ssl_incs_in = [
-                              '/usr/local/ssl/include',
-                              '/usr/contrib/ssl/include/'
+                              '@SSLBASE@/include'
                              ]
-        ssl_incs = find_file('openssl/ssl.h', inc_dirs,
-                             search_for_ssl_incs_in
+        ssl_incs = find_file('openssl/ssl.h', [],
+                             search_for_ssl_incs_in + inc_dirs
                              )
         if ssl_incs is not None:
             krb5_h = find_file('krb5.h', inc_dirs,
@@ -867,9 +870,7 @@ class PyBuildExt(build_ext):
             if krb5_h:
                 ssl_incs += krb5_h
         ssl_libs = find_library_file(self.compiler, 'ssl',lib_dirs,
-                                     ['/usr/local/ssl/lib',
-                                      '/usr/contrib/ssl/lib/'
-                                     ] )
+                                     [] )
 
         if (ssl_incs is not None and
             ssl_libs is not None):
@@ -885,10 +886,12 @@ class PyBuildExt(build_ext):
         openssl_ver = 0
         openssl_ver_re = re.compile(
             '^\s*#\s*define\s+OPENSSL_VERSION_NUMBER\s+(0x[0-9a-fA-F]+)' )
+        openssl_ver_major = re.compile(
+            '^\s*#\s*define\s+OPENSSL_VERSION_MAJOR\s+([0-9]+)' )
 
         # look for the openssl version header on the compiler search path.
         opensslv_h = find_file('openssl/opensslv.h', [],
-                inc_dirs + search_for_ssl_incs_in)
+                search_for_ssl_incs_in + inc_dirs)
         if opensslv_h:
             name = os.path.join(opensslv_h[0], 'openssl/opensslv.h')
             if host_platform == 'darwin' and is_macosx_sdk_path(name):
@@ -899,6 +902,10 @@ class PyBuildExt(build_ext):
                     m = openssl_ver_re.match(line)
                     if m:
                         openssl_ver = eval(m.group(1))
+                        break
+                    m = openssl_ver_major.match(line)
+                    if m and eval(m.group(1)) >= 3:
+                        openssl_ver = 0x03000000
             except IOError, msg:
                 print "IOError while reading opensshv.h:", msg
                 pass
@@ -988,175 +995,6 @@ class PyBuildExt(build_ext):
             else:
                 raise ValueError("unknown major BerkeleyDB version", major)
 
-        # construct a list of paths to look for the header file in on
-        # top of the normal inc_dirs.
-        db_inc_paths = [
-            '/usr/include/db4',
-            '/usr/local/include/db4',
-            '/opt/sfw/include/db4',
-            '/usr/include/db3',
-            '/usr/local/include/db3',
-            '/opt/sfw/include/db3',
-            # Fink defaults (http://fink.sourceforge.net/)
-            '/sw/include/db4',
-            '/sw/include/db3',
-        ]
-        # 4.x minor number specific paths
-        for x in gen_db_minor_ver_nums(4):
-            db_inc_paths.append('/usr/include/db4%d' % x)
-            db_inc_paths.append('/usr/include/db4.%d' % x)
-            db_inc_paths.append('/usr/local/BerkeleyDB.4.%d/include' % x)
-            db_inc_paths.append('/usr/local/include/db4%d' % x)
-            db_inc_paths.append('/pkg/db-4.%d/include' % x)
-            db_inc_paths.append('/opt/db-4.%d/include' % x)
-            # MacPorts default (http://www.macports.org/)
-            db_inc_paths.append('/opt/local/include/db4%d' % x)
-        # 3.x minor number specific paths
-        for x in gen_db_minor_ver_nums(3):
-            db_inc_paths.append('/usr/include/db3%d' % x)
-            db_inc_paths.append('/usr/local/BerkeleyDB.3.%d/include' % x)
-            db_inc_paths.append('/usr/local/include/db3%d' % x)
-            db_inc_paths.append('/pkg/db-3.%d/include' % x)
-            db_inc_paths.append('/opt/db-3.%d/include' % x)
-
-        if cross_compiling:
-            db_inc_paths = []
-
-        # Add some common subdirectories for Sleepycat DB to the list,
-        # based on the standard include directories. This way DB3/4 gets
-        # picked up when it is installed in a non-standard prefix and
-        # the user has added that prefix into inc_dirs.
-        std_variants = []
-        for dn in inc_dirs:
-            std_variants.append(os.path.join(dn, 'db3'))
-            std_variants.append(os.path.join(dn, 'db4'))
-            for x in gen_db_minor_ver_nums(4):
-                std_variants.append(os.path.join(dn, "db4%d"%x))
-                std_variants.append(os.path.join(dn, "db4.%d"%x))
-            for x in gen_db_minor_ver_nums(3):
-                std_variants.append(os.path.join(dn, "db3%d"%x))
-                std_variants.append(os.path.join(dn, "db3.%d"%x))
-
-        db_inc_paths = std_variants + db_inc_paths
-        db_inc_paths = [p for p in db_inc_paths if os.path.exists(p)]
-
-        db_ver_inc_map = {}
-
-        if host_platform == 'darwin':
-            sysroot = macosx_sdk_root()
-
-        class db_found(Exception): pass
-        try:
-            # See whether there is a Sleepycat header in the standard
-            # search path.
-            for d in inc_dirs + db_inc_paths:
-                f = os.path.join(d, "db.h")
-
-                if host_platform == 'darwin' and is_macosx_sdk_path(d):
-                    f = os.path.join(sysroot, d[1:], "db.h")
-
-                if db_setup_debug: print "db: looking for db.h in", f
-                if os.path.exists(f):
-                    f = open(f).read()
-                    m = re.search(r"#define\WDB_VERSION_MAJOR\W(\d+)", f)
-                    if m:
-                        db_major = int(m.group(1))
-                        m = re.search(r"#define\WDB_VERSION_MINOR\W(\d+)", f)
-                        db_minor = int(m.group(1))
-                        db_ver = (db_major, db_minor)
-
-                        # Avoid 4.6 prior to 4.6.21 due to a BerkeleyDB bug
-                        if db_ver == (4, 6):
-                            m = re.search(r"#define\WDB_VERSION_PATCH\W(\d+)", f)
-                            db_patch = int(m.group(1))
-                            if db_patch < 21:
-                                print "db.h:", db_ver, "patch", db_patch,
-                                print "being ignored (4.6.x must be >= 4.6.21)"
-                                continue
-
-                        if ( (db_ver not in db_ver_inc_map) and
-                            allow_db_ver(db_ver) ):
-                            # save the include directory with the db.h version
-                            # (first occurrence only)
-                            db_ver_inc_map[db_ver] = d
-                            if db_setup_debug:
-                                print "db.h: found", db_ver, "in", d
-                        else:
-                            # we already found a header for this library version
-                            if db_setup_debug: print "db.h: ignoring", d
-                    else:
-                        # ignore this header, it didn't contain a version number
-                        if db_setup_debug:
-                            print "db.h: no version number version in", d
-
-            db_found_vers = db_ver_inc_map.keys()
-            db_found_vers.sort()
-
-            while db_found_vers:
-                db_ver = db_found_vers.pop()
-                db_incdir = db_ver_inc_map[db_ver]
-
-                # check lib directories parallel to the location of the header
-                db_dirs_to_check = [
-                    db_incdir.replace("include", 'lib64'),
-                    db_incdir.replace("include", 'lib'),
-                ]
-
-                if host_platform != 'darwin':
-                    db_dirs_to_check = filter(os.path.isdir, db_dirs_to_check)
-
-                else:
-                    # Same as other branch, but takes OSX SDK into account
-                    tmp = []
-                    for dn in db_dirs_to_check:
-                        if is_macosx_sdk_path(dn):
-                            if os.path.isdir(os.path.join(sysroot, dn[1:])):
-                                tmp.append(dn)
-                        else:
-                            if os.path.isdir(dn):
-                                tmp.append(dn)
-                    db_dirs_to_check = tmp
-
-                # Look for a version specific db-X.Y before an ambiguous dbX
-                # XXX should we -ever- look for a dbX name?  Do any
-                # systems really not name their library by version and
-                # symlink to more general names?
-                for dblib in (('db-%d.%d' % db_ver),
-                              ('db%d%d' % db_ver),
-                              ('db%d' % db_ver[0])):
-                    dblib_file = self.compiler.find_library_file(
-                                    db_dirs_to_check + lib_dirs, dblib )
-                    if dblib_file:
-                        dblib_dir = [ os.path.abspath(os.path.dirname(dblib_file)) ]
-                        raise db_found
-                    else:
-                        if db_setup_debug: print "db lib: ", dblib, "not found"
-
-        except db_found:
-            if db_setup_debug:
-                print "bsddb using BerkeleyDB lib:", db_ver, dblib
-                print "bsddb lib dir:", dblib_dir, " inc dir:", db_incdir
-            db_incs = [db_incdir]
-            dblibs = [dblib]
-            # We add the runtime_library_dirs argument because the
-            # BerkeleyDB lib we're linking against often isn't in the
-            # system dynamic library search path.  This is usually
-            # correct and most trouble free, but may cause problems in
-            # some unusual system configurations (e.g. the directory
-            # is on an NFS server that goes away).
-            exts.append(Extension('_bsddb', ['_bsddb.c'],
-                                  depends = ['bsddb.h'],
-                                  library_dirs=dblib_dir,
-                                  runtime_library_dirs=dblib_dir,
-                                  include_dirs=db_incs,
-                                  libraries=dblibs))
-        else:
-            if db_setup_debug: print "db: no appropriate library found"
-            db_incs = None
-            dblibs = []
-            dblib_dir = None
-            missing.append('_bsddb')
-
         # The sqlite interface
         sqlite_setup_debug = False   # verbose debug prints from this script?
 
@@ -1262,46 +1100,32 @@ class PyBuildExt(build_ext):
         else:
             missing.append('_sqlite3')
 
-        # Look for Berkeley db 1.85.   Note that it is built as a different
-        # module name so it can be included even when later versions are
-        # available.  A very restrictive search is performed to avoid
-        # accidentally building this module with a later version of the
-        # underlying db library.  May BSD-ish Unixes incorporate db 1.85
-        # symbols into libc and place the include file in /usr/include.
-        #
-        # If the better bsddb library can be built (db_incs is defined)
-        # we do not build this one.  Otherwise this build will pick up
-        # the more recent berkeleydb's db.h file first in the include path
-        # when attempting to compile and it will fail.
-        f = "/usr/include/db.h"
-
-        if host_platform == 'darwin':
-            if is_macosx_sdk_path(f):
-                sysroot = macosx_sdk_root()
-                f = os.path.join(sysroot, f[1:])
-
-        if os.path.exists(f) and not db_incs:
-            data = open(f).read()
-            m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
-            if m is not None:
-                # bingo - old version used hash file format version 2
-                ### XXX this should be fixed to not be platform-dependent
-                ### but I don't have direct access to an osf1 platform and
-                ### seemed to be muffing the search somehow
-                libraries = host_platform == "osf1" and ['db'] or None
-                if libraries is not None:
-                    exts.append(Extension('bsddb185', ['bsddbmodule.c'],
-                                          libraries=libraries))
-                else:
-                    exts.append(Extension('bsddb185', ['bsddbmodule.c']))
-            else:
-                missing.append('bsddb185')
-        else:
-            missing.append('bsddb185')
-
         dbm_order = ['gdbm']
         # The standard Unix dbm module:
         if host_platform not in ['cygwin']:
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
@@ -1313,7 +1137,7 @@ class PyBuildExt(build_ext):
             dbmext = None
             for cand in dbm_order:
                 if cand == "ndbm":
-                    if find_file("ndbm.h", inc_dirs, []) is not None:
+                    if find_ndbm_h(inc_dirs) is not None:
                         # Some systems have -lndbm, others have -lgdbm_compat,
                         # others don't have either
                         if self.compiler.find_library_file(lib_dirs,
@@ -1357,18 +1181,14 @@ class PyBuildExt(build_ext):
                                 libraries = gdbm_libs)
                             break
                 elif cand == "bdb":
-                    if db_incs is not None:
-                        print "building dbm using bdb"
-                        dbmext = Extension('dbm', ['dbmmodule.c'],
-                                           library_dirs=dblib_dir,
-                                           runtime_library_dirs=dblib_dir,
-                                           include_dirs=db_incs,
-                                           define_macros=[
-                                               ('HAVE_BERKDB_H', None),
-                                               ('DB_DBM_HSEARCH', None),
-                                               ],
-                                           libraries=dblibs)
-                        break
+		    print "building dbm using bdb"
+		    dbmext = Extension('dbm', ['dbmmodule.c'],
+				       define_macros=[
+					   ('HAVE_BERKDB_H', None),
+					   ('DB_DBM_HSEARCH', None),
+					   ],
+				       libraries=["db"])
+		    break
             if dbmext is not None:
                 exts.append(dbmext)
             else:
@@ -1429,8 +1249,7 @@ class PyBuildExt(build_ext):
             missing.append('_curses')
 
         # If the curses module is enabled, check for the panel module
-        if (module_enabled(exts, '_curses') and
-            self.compiler.find_library_file(lib_dirs, panel_library)):
+        if (module_enabled(exts, '_curses')):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
                                    include_dirs = curses_incs,
                                    libraries = [panel_library] + curses_libs) )
@@ -2129,6 +1948,7 @@ class PyBuildExt(build_ext):
 
         if host_platform == 'darwin':
             sources.append('_ctypes/malloc_closure.c')
+            extra_compile_args.append('-DUSING_MALLOC_CLOSURE_DOT_C=1')
             sources.append('_ctypes/darwin/dlfcn_simple.c')
             extra_compile_args.append('-DMACOSX')
             include_dirs.append('_ctypes/darwin')
@@ -2191,6 +2011,16 @@ class PyBuildExt(build_ext):
                     break
 
         if ffi_inc and ffi_lib:
+            config = distutils.command.config.config(self.distribution)
+            config._check_compiler()
+            if any(cc in config.compiler.compiler_so for cc in ('gcc', 'clang')):
+                config.compiler.compiler_so += ["-Wno-unguarded-availability-new", "-Wno-unused-value"]
+            if config.check_func("ffi_prep_closure_loc", headers=['ffi.h'], include_dirs=[ffi_inc]):
+                ext.extra_compile_args.append("-DHAVE_FFI_PREP_CLOSURE_LOC=1")
+            if config.check_func("ffi_prep_cif_var", headers=['ffi.h'], include_dirs=[ffi_inc]):
+                ext.extra_compile_args.append("-DHAVE_FFI_PREP_CIF_VAR=1")
+            if host_platform == 'darwin' and config.check_func("ffi_closure_alloc", headers=['ffi.h'], include_dirs=[ffi_inc]):
+                ext.extra_compile_args.append("-DHAVE_FFI_CLOSURE_ALLOC=1")
             ext.include_dirs.extend(ffi_inc)
             ext.libraries.append(ffi_lib)
             self.use_system_libffi = True
@@ -2342,9 +2172,9 @@ def main():
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+          scripts = ['Tools/scripts/pydoc2.7',
+                     'Tools/scripts/2to3-2.7',
+                     'Tools/scripts/smtpd2.7.py']
         )
 
 # --install-platlib
