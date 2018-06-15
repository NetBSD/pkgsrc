$NetBSD: patch-scripts_mk__util.py,v 1.4 2018/06/15 15:11:35 jperkin Exp $

--- scripts/mk_util.py.orig	2016-11-07 22:02:30.000000000 +0000
+++ scripts/mk_util.py
@@ -69,6 +69,7 @@ IS_WINDOWS=False
 IS_LINUX=False
 IS_OSX=False
 IS_FREEBSD=False
+IS_NETBSD=False
 IS_OPENBSD=False
 IS_CYGWIN=False
 IS_CYGWIN_MINGW=False
@@ -95,6 +96,7 @@ VER_MINOR=None
 VER_BUILD=None
 VER_REVISION=None
 PREFIX=sys.prefix
+DESTDIR=""
 GMP=False
 FOCI2=False
 FOCI2LIB=''
@@ -139,6 +141,9 @@ def is_linux():
 def is_freebsd():
     return IS_FREEBSD
 
+def is_netbsd():
+    return IS_NETBSD
+
 def is_openbsd():
     return IS_OPENBSD
 
@@ -603,16 +608,18 @@ elif os.name == 'posix':
     if os.uname()[0] == 'Darwin':
         IS_OSX=True
         PREFIX="/usr/local"
-    elif os.uname()[0] == 'Linux':
-        IS_LINUX=True
     elif os.uname()[0] == 'FreeBSD':
         IS_FREEBSD=True
+    elif os.uname()[0] == 'NetBSD':
+        IS_NETBSD=True
     elif os.uname()[0] == 'OpenBSD':
         IS_OPENBSD=True
     elif os.uname()[0][:6] == 'CYGWIN':
         IS_CYGWIN=True
         if (CC != None and "mingw" in CC):
             IS_CYGWIN_MINGW=True
+    else:
+        IS_LINUX=True
 
 def display_help(exit_code):
     print("mk_make.py: Z3 Makefile generator\n")
@@ -623,6 +630,7 @@ def display_help(exit_code):
     print("  -s, --silent                  do not print verbose messages.")
     if not IS_WINDOWS:
         print("  -p <dir>, --prefix=<dir>      installation prefix (default: %s)." % PREFIX)
+	print("  -D <dir>, --destdir=<dir>     installation chroot (default: none).")
     else:
         print("  --parallel=num                use cl option /MP with 'num' parallel processes")
     print("  --pypkgdir=<dir>              Force a particular Python package directory (default %s)" % PYTHON_PACKAGE_DIR)
@@ -677,13 +685,13 @@ def display_help(exit_code):
 # Parse configuration option for mk_make script
 def parse_options():
     global VERBOSE, DEBUG_MODE, IS_WINDOWS, VS_X64, ONLY_MAKEFILES, SHOW_CPPS, VS_PROJ, TRACE, VS_PAR, VS_PAR_NUM
-    global DOTNET_ENABLED, DOTNET_KEY_FILE, JAVA_ENABLED, ML_ENABLED, STATIC_LIB, STATIC_BIN, PREFIX, GMP, FOCI2, FOCI2LIB, PYTHON_PACKAGE_DIR, GPROF, GIT_HASH, GIT_DESCRIBE, PYTHON_INSTALL_ENABLED, PYTHON_ENABLED
+    global DOTNET_ENABLED, DOTNET_KEY_FILE, JAVA_ENABLED, ML_ENABLED, STATIC_LIB, STATIC_BIN, PREFIX, DESTDIR, GMP, FOCI2, FOCI2LIB, PYTHON_PACKAGE_DIR, GPROF, GIT_HASH, GIT_DESCRIBE, PYTHON_INSTALL_ENABLED, PYTHON_ENABLED
     global LINUX_X64, SLOW_OPTIMIZE, USE_OMP
     try:
         options, remainder = getopt.gnu_getopt(sys.argv[1:],
                                                'b:df:sxhmcvtnp:gj',
                                                ['build=', 'debug', 'silent', 'x64', 'help', 'makefiles', 'showcpp', 'vsproj',
-                                                'trace', 'dotnet', 'dotnet-key=', 'staticlib', 'prefix=', 'gmp', 'foci2=', 'java', 'parallel=', 'gprof',
+                                                'trace', 'dotnet', 'dotnet-key=', 'staticlib', 'prefix=', 'destdir=', 'gmp', 'foci2=', 'java', 'parallel=', 'gprof',
                                                 'githash=', 'git-describe', 'x86', 'ml', 'optimize', 'noomp', 'pypkgdir=', 'python', 'staticbin'])
     except:
         print("ERROR: Invalid command line option")
@@ -727,6 +735,8 @@ def parse_options():
             SLOW_OPTIMIZE = True
         elif not IS_WINDOWS and opt in ('-p', '--prefix'):
             PREFIX = arg
+        elif not IS_WINDOWS and opt in ('-D', '--destdir'):
+            DESTDIR = arg
         elif opt in ('--pypkgdir'):
             PYTHON_PACKAGE_DIR = arg
         elif IS_WINDOWS and opt == '--parallel':
@@ -1208,9 +1218,9 @@ class ExeComponent(Component):
 
     def mk_unix_dist(self, build_path, dist_path):
         if self.install:
-            mk_dir(os.path.join(dist_path, INSTALL_BIN_DIR))
+            mk_dir(os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR))
             shutil.copy(os.path.join(build_path, self.exe_name),
-                        os.path.join(dist_path, INSTALL_BIN_DIR, self.exe_name))
+                        os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.exe_name))
 
 
 class ExtraExeComponent(ExeComponent):
@@ -1227,7 +1237,7 @@ def get_so_ext():
     sysname = os.uname()[0]
     if sysname == 'Darwin':
         return 'dylib'
-    elif sysname == 'Linux' or sysname == 'FreeBSD' or sysname == 'OpenBSD':
+    elif sysname == 'Linux' or sysname == 'FreeBSD' or sysname == 'NetBSD' or sysname == 'OpenBSD':
         return 'so'
     elif sysname == 'CYGWIN':
         return 'dll'
@@ -1381,12 +1391,12 @@ class DLLComponent(Component):
 
     def mk_unix_dist(self, build_path, dist_path):
         if self.install:
-            mk_dir(os.path.join(dist_path, INSTALL_BIN_DIR))
+            mk_dir(os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR))
             so = get_so_ext()
             shutil.copy('%s.%s' % (os.path.join(build_path, self.dll_name), so),
-                        '%s.%s' % (os.path.join(dist_path, INSTALL_BIN_DIR, self.dll_name), so))
+                        '%s.%s' % (os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.dll_name), so))
             shutil.copy('%s.a' % os.path.join(build_path, self.dll_name),
-                        '%s.a' % os.path.join(dist_path, INSTALL_BIN_DIR, self.dll_name))
+                        '%s.a' % os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.dll_name))
 
 class PythonComponent(Component): 
     def __init__(self, name, libz3Component):
@@ -1403,7 +1413,7 @@ class PythonComponent(Component):
             return
 
         src = os.path.join(build_path, 'python', 'z3')
-        dst = os.path.join(dist_path, INSTALL_BIN_DIR, 'python', 'z3')
+        dst = os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, 'python', 'z3')
         if os.path.exists(dst):
             shutil.rmtree(dst)
         shutil.copytree(src, dst)
@@ -1701,11 +1711,11 @@ class DotNetDLLComponent(Component):
 
     def mk_unix_dist(self, build_path, dist_path):
         if is_dotnet_enabled():
-            mk_dir(os.path.join(dist_path, INSTALL_BIN_DIR))
+            mk_dir(os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR))
             shutil.copy('%s.dll' % os.path.join(build_path, self.dll_name),
-                        '%s.dll' % os.path.join(dist_path, INSTALL_BIN_DIR, self.dll_name))
+                        '%s.dll' % os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.dll_name))
             shutil.copy('%s.xml' % os.path.join(build_path, self.dll_name),
-                        '%s.xml' % os.path.join(dist_path, INSTALL_BIN_DIR, self.dll_name))
+                        '%s.xml' % os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.dll_name))
 
     def mk_install_deps(self, out):
         if not is_dotnet_enabled():
@@ -1776,6 +1786,8 @@ class JavaDLLComponent(Component):
                 t = t.replace('PLATFORM', 'linux')
             elif IS_FREEBSD:
                 t = t.replace('PLATFORM', 'freebsd')
+            elif IS_NETBSD:
+                t = t.replace('PLATFORM', 'netbsd')
             elif IS_OPENBSD:
                 t = t.replace('PLATFORM', 'openbsd')
             elif IS_CYGWIN:
@@ -1827,12 +1839,12 @@ class JavaDLLComponent(Component):
 
     def mk_unix_dist(self, build_path, dist_path):
         if JAVA_ENABLED:
-            mk_dir(os.path.join(dist_path, INSTALL_BIN_DIR))
+            mk_dir(os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR))
             shutil.copy('%s.jar' % os.path.join(build_path, self.package_name),
-                        '%s.jar' % os.path.join(dist_path, INSTALL_BIN_DIR, self.package_name))
+                        '%s.jar' % os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, self.package_name))
             so = get_so_ext()
             shutil.copy(os.path.join(build_path, 'libz3java.%s' % so),
-                        os.path.join(dist_path, INSTALL_BIN_DIR, 'libz3java.%s' % so))
+                        os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, 'libz3java.%s' % so))
 
     def mk_install(self, out):
         if is_java_enabled() and self.install:
@@ -2437,7 +2449,7 @@ def mk_config():
         if sysname == 'Darwin':
             SO_EXT    = '.dylib'
             SLIBFLAGS = '-dynamiclib'
-        elif sysname == 'Linux':
+        elif sysname == 'Linux' or sysname == 'SunOS':
             CXXFLAGS       = '%s -fno-strict-aliasing -D_LINUX_' % CXXFLAGS
             OS_DEFINES     = '-D_LINUX_'
             SO_EXT         = '.so'
@@ -2451,6 +2463,13 @@ def mk_config():
             LDFLAGS        = '%s -lrt' % LDFLAGS
             SLIBFLAGS      = '-shared'
             SLIBEXTRAFLAGS = '%s -lrt' % SLIBEXTRAFLAGS
+        elif sysname == 'NetBSD':
+            CXXFLAGS       = '%s -fno-strict-aliasing -D_NETBSD_' % CXXFLAGS
+            OS_DEFINES     = '-D_NETBSD_'
+            SO_EXT         = '.so'
+            LDFLAGS        = '%s -lrt' % LDFLAGS
+            SLIBFLAGS      = '-shared'
+            SLIBEXTRAFLAGS = '%s -lrt' % SLIBEXTRAFLAGS
         elif sysname == 'OpenBSD':
             CXXFLAGS       = '%s -fno-strict-aliasing -D_OPENBSD_' % CXXFLAGS
             OS_DEFINES     = '-D_OPENBSD_'
@@ -2486,6 +2505,7 @@ def mk_config():
             LDFLAGS = '%s -static-libgcc -static-libstdc++' % LDFLAGS
                         
         config.write('PREFIX=%s\n' % PREFIX)
+        config.write('DESTDIR=%s\n' % DESTDIR)
         config.write('CC=%s\n' % CC)
         config.write('CXX=%s\n' % CXX)
         config.write('CXXFLAGS=%s %s\n' % (CPPFLAGS, CXXFLAGS))
@@ -2520,6 +2540,7 @@ def mk_config():
             print('Arithmetic:     %s' % ARITH)
             print('OpenMP:         %s' % HAS_OMP)
             print('Prefix:         %s' % PREFIX)
+            print('Destdir:        %s' % DESTDIR)
             print('64-bit:         %s' % is64())
             print('FP math:        %s' % FPMATH)
             print("Python pkg dir: %s" % PYTHON_PACKAGE_DIR)
@@ -2580,7 +2601,10 @@ def mk_makefile():
     pathvar = "DYLD_LIBRARY_PATH" if IS_OSX else "PATH" if IS_WINDOWS else "LD_LIBRARY_PATH"
     out.write("\t@echo \"Z3Py scripts stored in arbitrary directories can be executed if the \'%s\' directory is added to the PYTHONPATH environment variable and the \'%s\' directory is added to the %s environment variable.\"\n" % (os.path.join(BUILD_DIR, 'python'), BUILD_DIR, pathvar))
     if not IS_WINDOWS:
-        out.write("\t@echo Use the following command to install Z3 at prefix $(PREFIX).\n")
+        out.write("\t@echo Use the following command to install Z3 at prefix $(PREFIX)")
+	if DESTDIR != "":
+	    out.write(" under destdir $(DESTDIR)")
+	out.write(".\n")
         out.write('\t@echo "    sudo make install"\n\n')
         # out.write("\t@echo If you are doing a staged install you can use DESTDIR.\n")
         # out.write('\t@echo "    make DESTDIR=/some/temp/directory install"\n')
@@ -3283,7 +3307,7 @@ def mk_unix_dist(build_path, dist_path):
     # Add Z3Py to bin directory
     for pyc in filter(lambda f: f.endswith('.pyc') or f.endswith('.py'), os.listdir(build_path)):
         shutil.copy(os.path.join(build_path, pyc),
-                    os.path.join(dist_path, INSTALL_BIN_DIR, pyc))
+                    os.path.join(DESTDIR + dist_path, INSTALL_BIN_DIR, pyc))
 
 class MakeRuleCmd(object):
     """
