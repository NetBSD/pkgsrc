$NetBSD: patch-src_twisted_runner_portmap.c,v 1.1 2016/11/01 15:55:46 wiz Exp $

Let's be polite and let the system first include its headers before
Python redefines everything.

--- src/twisted/runner/portmap.c.orig	2016-10-26 02:57:22.000000000 +0000
+++ src/twisted/runner/portmap.c
@@ -7,9 +7,9 @@
 
 /* portmap.c: A simple Python wrapper for pmap_set(3) and pmap_unset(3) */
 
-#include <Python.h>
 #include <rpc/rpc.h>
 #include <rpc/pmap_clnt.h>
+#include <Python.h>
 
 static PyObject * portmap_set(PyObject *self, PyObject *args)
 {
