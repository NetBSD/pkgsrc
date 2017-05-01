$NetBSD: patch-src_kerberos.c,v 1.1.2.2 2017/05/01 09:38:31 bsiegert Exp $

Merge pull request #52 from kwlzn/kwlzn/none_principal_fix
Allow `authGSSClientInit` principal kwarg to be None.

--- src/kerberos.c.orig	2016-01-25 17:51:33.000000000 +0000
+++ src/kerberos.c
@@ -147,7 +147,7 @@ static PyObject* authGSSClientInit(PyObj
     int result = 0;
 
     if (! PyArg_ParseTupleAndKeywords(
-        args, keywds, "s|slOO", kwlist,
+        args, keywds, "s|zlOO", kwlist,
         &service, &principal, &gss_flags, &pydelegatestate, &pymech_oid
     )) {
         return NULL;
