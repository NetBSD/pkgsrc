$NetBSD: patch-Modules__ssl.c,v 1.1 2016/02/06 11:25:09 tron Exp $

Use CA certificate file provided by "mozilla-rootcerts" package by default

--- Modules/_ssl.c.orig	2015-12-05 19:47:13.000000000 +0000
+++ Modules/_ssl.c	2016-02-06 11:12:59.865409460 +0000
@@ -2952,10 +2952,12 @@
 static PyObject *
 set_default_verify_paths(PySSLContext *self, PyObject *unused)
 {
+    const char *cacert_pem = "@PREFIX@/share/mozilla-rootcerts/cacert.pem";
     if (!SSL_CTX_set_default_verify_paths(self->ctx)) {
         _setSSLError(NULL, 0, __FILE__, __LINE__);
         return NULL;
     }
+    SSL_CTX_load_verify_locations(self->ctx, cacert_pem, NULL);
     Py_RETURN_NONE;
 }
 
