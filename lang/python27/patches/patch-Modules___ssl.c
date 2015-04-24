$NetBSD: patch-Modules___ssl.c,v 1.5 2015/04/24 03:01:36 rodent Exp $

Fix build with LibreSSL.

--- Modules/_ssl.c.orig	2014-12-10 15:59:53.000000000 +0000
+++ Modules/_ssl.c
@@ -3301,6 +3301,11 @@ Returns 1 if the OpenSSL PRNG has been s
 It is necessary to seed the PRNG with RAND_add() on some platforms before\n\
 using the ssl() function.");
 
+#endif /* HAVE_OPENSSL_RAND */
+
+
+#ifdef HAVE_RAND_EGD
+
 static PyObject *
 PySSL_RAND_egd(PyObject *self, PyObject *arg)
 {
@@ -3327,7 +3332,7 @@ Queries the entropy gather daemon (EGD) 
 Returns number of bytes read.  Raises SSLError if connection to EGD\n\
 fails or if it does not provide enough data to seed PRNG.");
 
-#endif /* HAVE_OPENSSL_RAND */
+#endif /* HAVE_RAND_EGD */
 
 
 PyDoc_STRVAR(PySSL_get_default_verify_paths_doc,
@@ -3720,10 +3725,12 @@ static PyMethodDef PySSL_methods[] = {
 #ifdef HAVE_OPENSSL_RAND
     {"RAND_add",            PySSL_RAND_add, METH_VARARGS,
      PySSL_RAND_add_doc},
+{"RAND_status",         (PyCFunction)PySSL_RAND_status, METH_NOARGS,
+     PySSL_RAND_status_doc},
+#endif
+#ifdef HAVE_RAND_EGD
     {"RAND_egd",            PySSL_RAND_egd, METH_VARARGS,
      PySSL_RAND_egd_doc},
-    {"RAND_status",         (PyCFunction)PySSL_RAND_status, METH_NOARGS,
-     PySSL_RAND_status_doc},
 #endif
     {"get_default_verify_paths", (PyCFunction)PySSL_get_default_verify_paths,
      METH_NOARGS, PySSL_get_default_verify_paths_doc},
