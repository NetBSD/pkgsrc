$NetBSD: patch-Modules___ssl.c,v 1.1 2015/04/24 03:24:32 rodent Exp $

Fix build with LibreSSL.

--- Modules/_ssl.c.orig	2014-10-12 07:03:53.000000000 +0000
+++ Modules/_ssl.c
@@ -2559,6 +2559,7 @@ Returns 1 if the OpenSSL PRNG has been s
 It is necessary to seed the PRNG with RAND_add() on some platforms before\n\
 using the ssl() function.");
 
+#ifdef HAVE_RAND_EGD
 static PyObject *
 PySSL_RAND_egd(PyObject *self, PyObject *args)
 {
@@ -2586,6 +2587,7 @@ PyDoc_STRVAR(PySSL_RAND_egd_doc,
 Queries the entropy gather daemon (EGD) on the socket named by 'path'.\n\
 Returns number of bytes read.  Raises SSLError if connection to EGD\n\
 fails or if it does not provide enough data to seed PRNG.");
+#endif /* HAVE_RAND_EGD */
 
 #endif /* HAVE_OPENSSL_RAND */
 
@@ -2604,8 +2606,10 @@ static PyMethodDef PySSL_methods[] = {
      PySSL_RAND_bytes_doc},
     {"RAND_pseudo_bytes",   PySSL_RAND_pseudo_bytes, METH_VARARGS,
      PySSL_RAND_pseudo_bytes_doc},
+#ifdef HAVE_RAND_EGD
     {"RAND_egd",            PySSL_RAND_egd, METH_VARARGS,
      PySSL_RAND_egd_doc},
+#endif
     {"RAND_status",         (PyCFunction)PySSL_RAND_status, METH_NOARGS,
      PySSL_RAND_status_doc},
 #endif
