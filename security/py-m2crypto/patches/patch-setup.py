$NetBSD: patch-setup.py,v 1.2 2014/06/01 23:51:25 rodent Exp $

Don't pass "-includeall" to swig.  It causes compiler-dependent
tests in system include files to break (e.g. "#ifdef __GNUC__"
doesn't work properly.)

--- setup.py.orig	2014-01-22 19:36:53.000000000 +0000
+++ setup.py
@@ -75,7 +75,7 @@ class _M2CryptoBuildExt(build_ext.build_
 
         self.swig_opts = ['-I%s' % i for i in self.include_dirs + \
                           [opensslIncludeDir, os.path.join(opensslIncludeDir, "openssl")]]
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
 
         # Fedora does hat tricks.
