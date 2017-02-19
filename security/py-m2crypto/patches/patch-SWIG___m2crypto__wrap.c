$NetBSD: patch-SWIG___m2crypto__wrap.c,v 1.1 2017/02/19 18:54:39 adam Exp $

Avoid conflict with hmac() definition from stdlib.h (NetBSD).

--- SWIG/_m2crypto_wrap.c.orig	2017-02-19 18:35:59.000000000 +0000
+++ SWIG/_m2crypto_wrap.c
@@ -5050,7 +5050,7 @@ PyObject *hmac_final(HMAC_CTX *ctx) {
     return ret;
 }
 
-PyObject *hmac(PyObject *key, PyObject *data, const EVP_MD *md) {
+PyObject *hmac_func(PyObject *key, PyObject *data, const EVP_MD *md) {
     const void *kbuf, *dbuf;
     void *blob;
     int klen;
@@ -12676,7 +12676,7 @@ SWIGINTERN PyObject *_wrap_hmac(PyObject
       SWIG_exception(SWIG_ValueError,"Received a NULL pointer.");
     }
   }
-  result = (PyObject *)hmac(arg1,arg2,(EVP_MD const *)arg3);
+  result = (PyObject *)hmac_func(arg1,arg2,(EVP_MD const *)arg3);
   {
     resultobj=result;
   }
