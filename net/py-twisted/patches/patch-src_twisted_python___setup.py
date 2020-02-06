$NetBSD: patch-src_twisted_python___setup.py,v 1.3 2020/02/06 15:44:58 adam Exp $

Allow building with a c99 compiler on SunOS

--- src/twisted/python/_setup.py.orig	2019-11-02 16:29:27.000000000 +0000
+++ src/twisted/python/_setup.py
@@ -355,8 +355,7 @@ class build_ext_twisted(build_ext.build_
         # https://stackoverflow.com/questions/1034587).  See the documentation
         # of X/Open CAE in the standards(5) man page of Solaris.
         if sys.platform.startswith('sunos'):
-            self.define_macros.append(('_XOPEN_SOURCE', 1))
-            self.define_macros.append(('_XOPEN_SOURCE_EXTENDED', 1))
+            self.define_macros.append(('_XOPEN_SOURCE', 600))
 
         self.extensions = [
             x for x in self.conditionalExtensions if x.condition(self)
