$NetBSD: patch-src_ptclib_pxmlrpc.cxx,v 1.1 2016/07/16 03:23:50 markd Exp $

gcc6 fix

--- src/ptclib/pxmlrpc.cxx.orig	2012-08-23 02:12:41.000000000 +0000
+++ src/ptclib/pxmlrpc.cxx
@@ -727,7 +727,7 @@ PXMLElement * PXMLRPCBlock::GetParam(PIN
   }
 
   if (param == NULL)
-    return PFalse;
+    return NULL;
 
   for (i = 0; i < param->GetSize(); i++) {
     PXMLObject * parm = param->GetElement(i);
