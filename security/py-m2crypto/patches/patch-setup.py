$NetBSD: patch-setup.py,v 1.3 2017/02/19 18:54:39 adam Exp $

Don't pass "-includeall" to swig.  It causes compiler-dependent
tests in system include files to break (e.g. "#ifdef __GNUC__"
doesn't work properly.)

--- setup.py.orig	2016-07-22 12:43:17.000000000 +0000
+++ setup.py
@@ -112,7 +112,6 @@ class _M2CryptoBuildExt(build_ext.build_
             self.swig_opts.append('-D%s' % arch)
 
         self.swig_opts.extend(['-I%s' % i for i in self.include_dirs])
-        self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
