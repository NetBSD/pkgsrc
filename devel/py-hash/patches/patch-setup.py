$NetBSD: patch-setup.py,v 1.3 2018/06/30 19:01:52 fhajny Exp $

print is a function in Python 3.

--- setup.py.orig	2014-07-29 06:26:59.000000000 +0000
+++ setup.py
@@ -3,6 +3,7 @@
 import sys
 import os
 import math
+import platform
 
 from ez_setup import use_setuptools
 use_setuptools()
@@ -56,14 +57,16 @@ elif os.name == "posix" and sys.platform
         '/opt/local/include',
         '/usr/local/include'
     ]
-    libraries += ["boost_python-mt"]
-    extra_compile_args += ["-msse4.2"]
+    libraries += ["boost_python" + os.environ.get('PYVER') + "-mt"]
+    if platform.machine() in ("i386", "amd64"):
+        extra_compile_args += ["-msse4.2"]
 elif os.name == "posix":
-    libraries += ["boost_python", "rt"]
-    extra_compile_args += ["-msse4.2"]
+    libraries += ["boost_python" + os.environ.get('PYVER'), "rt"]
+    if platform.machine() in ("i386", "amd64"):
+        extra_compile_args += ["-msse4.2"]
 
 if os.getenv('TRAVIS') == 'true':
-    print "force to link boost::python base on Python version v%d.%d" % (sys.version_info.major, sys.version_info.minor)
+    print("force to link boost::python base on Python version v%d.%d" % (sys.version_info.major, sys.version_info.minor))
 
     os.remove('/usr/lib/libboost_python.so')
     os.symlink('/usr/lib/libboost_python-py%d%d.so' % (sys.version_info.major, sys.version_info.minor),
