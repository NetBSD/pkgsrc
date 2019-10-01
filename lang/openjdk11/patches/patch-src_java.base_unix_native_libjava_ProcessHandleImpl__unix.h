$NetBSD: patch-src_java.base_unix_native_libjava_ProcessHandleImpl__unix.h,v 1.1 2019/10/01 12:36:34 tnn Exp $

waitid(2) is available from NetBSD>=7.99.27

--- src/java.base/unix/native/libjava/ProcessHandleImpl_unix.h.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/java.base/unix/native/libjava/ProcessHandleImpl_unix.h
@@ -75,6 +75,6 @@ extern void unix_fillArgArray(JNIEnv *en
 
 extern void os_initNative(JNIEnv *env, jclass clazz);
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && __NetBSD_Version < 799002700)
 extern int os_waitForProcessExitNoReap(pid_t pid);
 #endif
