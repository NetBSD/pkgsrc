$NetBSD: patch-libjava_prims.cc,v 1.2 2014/11/28 09:57:32 obache Exp $

--- libjava/prims.cc.orig	2011-11-24 07:18:16.000000000 +0000
+++ libjava/prims.cc
@@ -1143,7 +1143,11 @@ namespace gcj
   bool verifyClasses = true;
 
   // Thread stack size specified by the -Xss runtime argument.
+#ifdef __OpenBSD__
+  size_t stack_size = 768*1024;
+#else
   size_t stack_size = 0;
+#endif
 
   // Start time of the VM
   jlong startTime = 0;
