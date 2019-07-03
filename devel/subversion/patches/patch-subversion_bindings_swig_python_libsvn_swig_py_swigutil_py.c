$NetBSD: patch-subversion_bindings_swig_python_libsvn_swig_py_swigutil_py.c,v 1.1 2019/07/03 10:42:54 markd Exp $

From: Stefan Sperling <stsp@apache.org>
Date: Fri, 12 Apr 2019 09:27:33 +0000
Subject: [PATCH] Get rid of apr_int64_t format string check in swig py
 configure.

This check relied on APR implementation details and broke with APR 1.7.0.
Rather than trying to guess a perfect format string to use, just use the
largest possible format and cast the argument accordingly.

Should fix build against APR 1.7.0 and later.

Suggested by: brane

* build/ac-macros/swig.m4: Remove code related to SVN_APR_INT64_T_PYCFMT.

* subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c
  (svn_swig_py_client_blame_receiver_func): Stop relying on the
   SVN_APR_INT64_T_PYCFMT constant from configure. Use "L" and
   acast to PY_LONG_LONG instead.

--- subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c.orig	2018-12-12 13:57:17.000000000 +0000
+++ subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c
@@ -46,7 +46,7 @@
 #include "svn_mergeinfo.h"
 #include "svn_types.h"
 
-#include "svn_private_config.h" /* for SVN_APR_INT64_T_PYCFMT */
+#include "svn_private_config.h"
 
 #include "swig_python_external_runtime.swg"
 #include "swigutil_py.h"
@@ -3394,10 +3394,9 @@ svn_error_t *svn_swig_py_client_blame_re
   svn_swig_py_acquire_py_lock();
 
   if ((result = PyObject_CallFunction(receiver,
-                                      (char *)
-                                      (SVN_APR_INT64_T_PYCFMT "lsssO&"),
-                                      line_no, revision, author, date, line,
-                                      make_ob_pool, pool)) == NULL)
+                                      (char *)"LlsssO&",
+                                      (PY_LONG_LONG)line_no, revision, author,
+                                      date, line, make_ob_pool, pool)) == NULL)
     {
       err = callback_exception_error();
     }
