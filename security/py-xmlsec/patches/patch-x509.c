$NetBSD: patch-x509.c,v 1.1 2018/12/27 15:13:01 joerg Exp $

--- x509.c.orig	2018-12-25 21:26:30.562985375 +0000
+++ x509.c
@@ -23,16 +23,16 @@ PyObject *xmlsec_X509DataGetNodeContent(
   xmlSecKeyInfoCtxPtr keyInfoCtx;
   int ret;
 
-  if (CheckArgs(args, "OIO:x509DataGetNodeContent")) {
-    if (!PyArg_ParseTuple(args, "OiO:x509DataGetNodeContent", &node_obj,
-			  &deleteChildren, &keyInfoCtx_obj))
+  if (CheckArgs(args, "OO:x509DataGetNodeContent")) {
+    if (!PyArg_ParseTuple(args, "OO:x509DataGetNodeContent", &node_obj,
+			  &keyInfoCtx_obj))
       return NULL;
   }
   else return NULL;
 
   node = xmlNodePtr_get(node_obj);
   keyInfoCtx = xmlSecKeyInfoCtxPtr_get(keyInfoCtx_obj);
-  ret = xmlSecX509DataGetNodeContent(node, deleteChildren, keyInfoCtx);
+  ret = xmlSecX509DataGetNodeContent(node, keyInfoCtx);
 
   return wrap_int(ret);
 }
