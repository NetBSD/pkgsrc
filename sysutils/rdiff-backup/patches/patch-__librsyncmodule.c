$NetBSD: patch-__librsyncmodule.c,v 1.1 2015/09/17 17:53:35 joerg Exp $

--- _librsyncmodule.c.orig	2015-09-17 15:50:26.000000000 +0000
+++ _librsyncmodule.c
@@ -59,8 +59,7 @@ _librsync_new_sigmaker(PyObject* self, P
   if (sm == NULL) return NULL;
   sm->x_attr = NULL;
 
-  sm->sig_job = rs_sig_begin((size_t)blocklen,
-							 (size_t)RS_DEFAULT_STRONG_LEN);
+  sm->sig_job = rs_sig_begin((size_t)blocklen, 8, RS_MD4_SIG_MAGIC);
   return (PyObject*)sm;
 }
 
