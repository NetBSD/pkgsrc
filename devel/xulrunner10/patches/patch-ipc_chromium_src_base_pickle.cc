$NetBSD: patch-ipc_chromium_src_base_pickle.cc,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- ipc/chromium/src/base/pickle.cc.orig	2013-01-03 17:43:14.000000000 +0000
+++ ipc/chromium/src/base/pickle.cc
@@ -456,7 +456,7 @@ char* Pickle::BeginWriteData(int length)
     "There can only be one variable buffer in a Pickle";
 
   if (!WriteInt(length))
-    return false;
+    return NULL;
 
   char *data_ptr = BeginWrite(length);
   if (!data_ptr)
