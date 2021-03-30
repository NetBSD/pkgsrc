$NetBSD: patch-src_kptydevice.cpp,v 1.2 2021/03/30 10:58:23 markd Exp $

NetBSD like FreeBSD

--- src/kptydevice.cpp.orig	2021-03-06 16:29:41.000000000 +0000
+++ src/kptydevice.cpp
@@ -29,7 +29,7 @@
 #include <sys/time.h>
 #endif
 
-#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 // "the other end's output queue size" - kinda braindead, huh?
 #define PTY_BYTES_AVAILABLE TIOCOUTQ
 #elif defined(TIOCINQ)
