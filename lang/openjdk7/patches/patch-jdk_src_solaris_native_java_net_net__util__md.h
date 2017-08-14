$NetBSD: patch-jdk_src_solaris_native_java_net_net__util__md.h,v 1.2 2017/08/14 00:02:16 ryoon Exp $

--- jdk/src/solaris/native/java/net/net_util_md.h.orig	2017-08-13 05:55:21.000000000 +0000
+++ jdk/src/solaris/native/java/net/net_util_md.h
@@ -46,7 +46,7 @@
    close subroutine does not return until the select call returns.
    ...
 */
-#if defined(__linux__) || defined(__FreeBSD__) || defined(MACOSX) || defined (_AIX)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(MACOSX) || defined (_AIX) || defined(__DragonFly__)
 extern int NET_Timeout(int s, long timeout);
 extern int NET_Read(int s, void* buf, size_t len);
 extern int NET_RecvFrom(int s, void *buf, int len, unsigned int flags,
