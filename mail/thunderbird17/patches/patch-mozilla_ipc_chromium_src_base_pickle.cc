$NetBSD: patch-mozilla_ipc_chromium_src_base_pickle.cc,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/ipc/chromium/src/base/pickle.cc.orig	2013-07-12 14:44:01.000000000 +0000
+++ mozilla/ipc/chromium/src/base/pickle.cc
@@ -492,7 +492,7 @@ char* Pickle::BeginWriteData(int length)
     "There can only be one variable buffer in a Pickle";
 
   if (!WriteInt(length))
-    return false;
+    return NULL;
 
   char *data_ptr = BeginWrite(length, sizeof(uint32));
   if (!data_ptr)
