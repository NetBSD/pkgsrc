$NetBSD: patch-Modules___multiprocessing_multiprocessing.c,v 1.1 2014/06/01 13:38:16 ryoon Exp $



--- Modules/_multiprocessing/multiprocessing.c.orig	2014-05-19 05:19:39.000000000 +0000
+++ Modules/_multiprocessing/multiprocessing.c
@@ -128,7 +128,9 @@ static PyMethodDef module_methods[] = {
     {"recv", multiprocessing_recv, METH_VARARGS, ""},
     {"send", multiprocessing_send, METH_VARARGS, ""},
 #endif
+#if !defined(POSIX_SEMAPHORES_NOT_ENABLED)
     {"sem_unlink", _PyMp_sem_unlink, METH_VARARGS, ""},
+#endif
     {NULL}
 };
 
