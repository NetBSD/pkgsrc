$NetBSD: patch-jdk_src_solaris_native_java_net_net__util__md.h,v 1.1.2.2 2014/07/27 12:36:21 spz Exp $

--- jdk/src/solaris/native/java/net/net_util_md.h.orig	2014-06-14 20:38:31.000000000 +0000
+++ jdk/src/solaris/native/java/net/net_util_md.h
@@ -37,7 +37,7 @@
 #endif
 
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(MACOSX)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(MACOSX) || defined(__DragonFly__)
 extern int NET_Timeout(int s, long timeout);
 extern int NET_Read(int s, void* buf, size_t len);
 extern int NET_RecvFrom(int s, void *buf, int len, unsigned int flags,
