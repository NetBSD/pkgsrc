$NetBSD: patch-libjava_prims.cc,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libjava/prims.cc.orig	2011-11-24 07:18:16.000000000 +0000
+++ libjava/prims.cc
@@ -1143,7 +1143,7 @@ namespace gcj
   bool verifyClasses = true;
 
   // Thread stack size specified by the -Xss runtime argument.
-  size_t stack_size = 0;
+  size_t stack_size = 768*1024;
 
   // Start time of the VM
   jlong startTime = 0;
