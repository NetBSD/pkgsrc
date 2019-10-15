$NetBSD: patch-Lib_ctypes_util.py,v 1.1 2019/10/15 16:50:11 adam Exp $

Fallback to clang.

Look for shared libraries in PkgSrc prefix.
Note: /usr/local will get replaced by SUBST.

Pull in patch for http://bugs.python.org/issue23287 for SunOS

--- Lib/ctypes/util.py.orig	2019-03-25 20:21:05.000000000 +0000
+++ Lib/ctypes/util.py
@@ -102,6 +102,8 @@ elif os.name == "posix":
 
         c_compiler = shutil.which('gcc')
         if not c_compiler:
+            c_compiler = shutil.which('clang')
+        if not c_compiler:
             c_compiler = shutil.which('cc')
         if not c_compiler:
             # No C compiler available, give up
@@ -213,34 +215,15 @@ elif os.name == "posix":
 
     elif sys.platform == "sunos5":
 
-        def _findLib_crle(name, is64):
-            if not os.path.exists('/usr/bin/crle'):
-                return None
+        def _findLib_path(name, is64):
 
             env = dict(os.environ)
             env['LC_ALL'] = 'C'
 
             if is64:
-                args = ('/usr/bin/crle', '-64')
+                paths = "/lib/64:/usr/lib/64:/usr/local/lib"
             else:
-                args = ('/usr/bin/crle',)
-
-            paths = None
-            try:
-                proc = subprocess.Popen(args,
-                                        stdout=subprocess.PIPE,
-                                        stderr=subprocess.DEVNULL,
-                                        env=env)
-            except OSError:  # E.g. bad executable
-                return None
-            with proc:
-                for line in proc.stdout:
-                    line = line.strip()
-                    if line.startswith(b'Default Library Path (ELF):'):
-                        paths = os.fsdecode(line).split()[4]
-
-            if not paths:
-                return None
+                paths = "/lib:/usr/lib:/usr/local/lib"
 
             for dir in paths.split(":"):
                 libfile = os.path.join(dir, "lib%s.so" % name)
@@ -250,7 +233,7 @@ elif os.name == "posix":
             return None
 
         def find_library(name, is64 = False):
-            return _get_soname(_findLib_crle(name, is64) or _findLib_gcc(name))
+            return _get_soname(_findLib_path(name, is64) or _findLib_gcc(name))
 
     else:
 
@@ -287,7 +270,7 @@ elif os.name == "posix":
         def _findLib_ld(name):
             # See issue #9998 for why this is needed
             expr = r'[^\(\)\s]*lib%s\.[^\(\)\s]*' % re.escape(name)
-            cmd = ['ld', '-t']
+            cmd = ['ld', '-t', '-L', '/usr/local/lib']
             libpath = os.environ.get('LD_LIBRARY_PATH')
             if libpath:
                 for d in libpath.split(':'):
