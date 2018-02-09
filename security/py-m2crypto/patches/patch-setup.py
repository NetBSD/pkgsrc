$NetBSD: patch-setup.py,v 1.4 2018/02/09 08:44:50 adam Exp $

Don't pass "-includeall" to swig.  It causes compiler-dependent
tests in system include files to break (e.g. "#ifdef __GNUC__"
doesn't work properly.)

--- setup.py.orig	2018-02-08 18:54:48.000000000 +0000
+++ setup.py
@@ -192,7 +192,6 @@ class _M2CryptoBuildExt(build_ext.build_
 
         # swig seems to need the default header file directories
         self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
-        self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
