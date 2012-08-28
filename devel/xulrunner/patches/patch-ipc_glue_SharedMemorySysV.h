$NetBSD: patch-ipc_glue_SharedMemorySysV.h,v 1.2 2012/08/28 23:27:10 ryoon Exp $

--- ipc/glue/SharedMemorySysV.h.orig	2012-08-24 22:55:37.000000000 +0000
+++ ipc/glue/SharedMemorySysV.h
@@ -8,7 +8,7 @@
 #ifndef mozilla_ipc_SharedMemorySysV_h
 #define mozilla_ipc_SharedMemorySysV_h
 
-#if defined(OS_LINUX) && !defined(ANDROID)
+#if (defined(OS_LINUX) && !defined(ANDROID)) || defined(OS_BSD)
 
 // SysV shared memory isn't available on Windows, but we define the
 // following macro so that #ifdefs are clearer (compared to #ifdef
