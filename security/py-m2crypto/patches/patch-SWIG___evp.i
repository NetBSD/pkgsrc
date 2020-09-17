$NetBSD: patch-SWIG___evp.i,v 1.1 2020/09/17 08:56:38 jperkin Exp $

Avoid conflict with hmac() definition from stdlib.h (NetBSD).

--- SWIG/_evp.i.orig	2020-04-14 21:09:41.000000000 +0000
+++ SWIG/_evp.i
@@ -361,7 +361,7 @@ PyObject *hmac_final(HMAC_CTX *ctx) {
     return ret;
 }
 
-PyObject *hmac(PyObject *key, PyObject *data, const EVP_MD *md) {
+PyObject *hmac_func(PyObject *key, PyObject *data, const EVP_MD *md) {
     const void *kbuf, *dbuf;
     void *blob;
     int klen = 0;
