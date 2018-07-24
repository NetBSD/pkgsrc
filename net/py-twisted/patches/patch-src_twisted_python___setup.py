$NetBSD: patch-src_twisted_python___setup.py,v 1.2 2018/07/24 15:10:04 adam Exp $

Allow building with a c99 compiler on SunOS

--- src/twisted/python/_setup.py.orig	2017-09-23 05:51:46.000000000 +0000
+++ src/twisted/python/_setup.py
@@ -293,8 +293,7 @@ class build_ext_twisted(build_ext.build_
         # http://stackoverflow.com/questions/1034587).  See the documentation
         # of X/Open CAE in the standards(5) man page of Solaris.
         if sys.platform.startswith('sunos'):
-            self.define_macros.append(('_XOPEN_SOURCE', 1))
-            self.define_macros.append(('_XOPEN_SOURCE_EXTENDED', 1))
+            self.define_macros.append(('_XOPEN_SOURCE', 600))
 
         self.extensions = [
             x for x in self.conditionalExtensions if x.condition(self)
