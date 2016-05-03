$NetBSD: patch-setup.py,v 1.1 2016/05/03 14:53:05 fhajny Exp $

print is a function in Python 3.

--- setup.py.orig	2014-07-29 06:26:59.000000000 +0000
+++ setup.py
@@ -63,7 +63,7 @@ elif os.name == "posix":
     extra_compile_args += ["-msse4.2"]
 
 if os.getenv('TRAVIS') == 'true':
-    print "force to link boost::python base on Python version v%d.%d" % (sys.version_info.major, sys.version_info.minor)
+    print("force to link boost::python base on Python version v%d.%d" % (sys.version_info.major, sys.version_info.minor))
 
     os.remove('/usr/lib/libboost_python.so')
     os.symlink('/usr/lib/libboost_python-py%d%d.so' % (sys.version_info.major, sys.version_info.minor),
