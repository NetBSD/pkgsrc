$NetBSD: patch-setup.py,v 1.1 2012/01/22 10:05:19 apb Exp $

Don't pass "-includeall" to swig.  It causes compiler-dependent
tests in system include files to break (e.g. "#ifdef __GNUC__"
doesn't work properly.)

--- setup.py.orig	2011-01-15 19:10:06.000000000 +0000
+++ setup.py
@@ -54,7 +54,7 @@ class _M2CryptoBuildExt(build_ext.build_
         
         self.swig_opts = ['-I%s' % i for i in self.include_dirs + \
                           [opensslIncludeDir]]
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         #self.swig_opts.append('-D__i386__') # Uncomment for early OpenSSL 0.9.7 versions, or on Fedora Core if build fails
         #self.swig_opts.append('-DOPENSSL_NO_EC') # Try uncommenting if you can't build with EC disabled
         
