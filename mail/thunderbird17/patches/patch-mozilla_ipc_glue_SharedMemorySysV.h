$NetBSD: patch-mozilla_ipc_glue_SharedMemorySysV.h,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/ipc/glue/SharedMemorySysV.h.orig	2012-11-19 22:42:22.000000000 +0000
+++ mozilla/ipc/glue/SharedMemorySysV.h
@@ -8,7 +8,7 @@
 #ifndef mozilla_ipc_SharedMemorySysV_h
 #define mozilla_ipc_SharedMemorySysV_h
 
-#if defined(OS_LINUX) && !defined(ANDROID)
+#if (defined(OS_LINUX) && !defined(ANDROID)) || defined(OS_BSD)
 
 // SysV shared memory isn't available on Windows, but we define the
 // following macro so that #ifdefs are clearer (compared to #ifdef
