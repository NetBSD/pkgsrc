$NetBSD: patch-duplicity___librsyncmodule.c,v 1.1 2015/09/17 17:53:35 joerg Exp $

--- duplicity/_librsyncmodule.c.orig	2014-10-20 19:09:10.000000000 +0000
+++ duplicity/_librsyncmodule.c
@@ -67,8 +67,7 @@ _librsync_new_sigmaker(PyObject* self, P
   sm = PyObject_New(_librsync_SigMakerObject, &_librsync_SigMakerType);
   if (sm == NULL) return NULL;
 
-  sm->sig_job = rs_sig_begin((size_t)blocklen,
-                             (size_t)RS_DEFAULT_STRONG_LEN);
+  sm->sig_job = rs_sig_begin((size_t)blocklen, 8, RS_MD4_SIG_MAGIC);
   return (PyObject*)sm;
 }
 
