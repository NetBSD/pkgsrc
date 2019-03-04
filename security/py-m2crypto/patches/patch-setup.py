$NetBSD: patch-setup.py,v 1.5 2019/03/04 18:41:48 adam Exp $

CPP may contain spaces.

Don't pass "-includeall" to swig.  It causes compiler-dependent
tests in system include files to break (e.g. "#ifdef __GNUC__"
doesn't work properly.)

--- setup.py.orig	2019-03-04 17:27:03.000000000 +0000
+++ setup.py
@@ -50,7 +50,7 @@ def _get_additional_includes():
                                 '*Visual*', 'VC', 'include')
         err = glob.glob(globmask)
     else:
-        pid = subprocess.Popen([os.environ.get('CPP', 'cpp'), '-Wp,-v', '-'],
+        pid = subprocess.Popen(os.environ.get('CPP', 'cpp').split() + ['-Wp,-v', '-'],
                                stdin=open(os.devnull, 'r'),
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
@@ -197,7 +197,6 @@ class _M2CryptoBuildExt(build_ext.build_
 
         # swig seems to need the default header file directories
         self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
-        self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
