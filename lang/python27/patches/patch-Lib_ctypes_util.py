$NetBSD: patch-Lib_ctypes_util.py,v 1.1 2018/06/17 19:21:21 adam Exp $

Find libraries using 'ld' (taken from Python 3.7).
Note: /usr/local will get replaced by SUBST.

--- Lib/ctypes/util.py.orig	2018-05-22 08:00:59.000000000 +0000
+++ Lib/ctypes/util.py
@@ -270,8 +270,32 @@ elif os.name == "posix":
                 return None
             return res.group(1)
 
+        def _findLib_ld(name):
+            # See issue #9998 for why this is needed
+            expr = r'[^\(\)\s]*lib%s\.[^\(\)\s]*' % re.escape(name)
+            cmd = ['ld', '-t', '-L', '/usr/local/lib']
+            libpath = os.environ.get('LD_LIBRARY_PATH')
+            if libpath:
+                for d in libpath.split(':'):
+                    cmd.extend(['-L', d])
+            cmd.extend(['-o', os.devnull, '-l%s' % name])
+            result = None
+            try:
+                p = subprocess.Popen(cmd, stdout=subprocess.PIPE,
+                                     stderr=subprocess.PIPE,
+                                     universal_newlines=True)
+                out, _ = p.communicate()
+                res = re.search(expr, os.fsdecode(out))
+                if res:
+                    result = res.group(0)
+            except Exception as e:
+                pass  # result will be None
+            return result
+
         def find_library(name):
-            return _findSoname_ldconfig(name) or _get_soname(_findLib_gcc(name))
+            # See issue #9998
+            return _findSoname_ldconfig(name) or \
+                   _get_soname(_findLib_gcc(name) or _findLib_ld(name))
 
 ################################################################
 # test code
