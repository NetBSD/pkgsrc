$NetBSD: patch-src_kptydevice.cpp,v 1.1 2024/05/26 12:02:20 markd Exp $

NetBSD like FreeBSD

--- src/kptydevice.cpp.orig	2022-04-02 10:26:01.000000000 +0000
+++ src/kptydevice.cpp
@@ -29,7 +29,7 @@
 #include <sys/time.h>
 #endif
 
-#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 // "the other end's output queue size" -- that is is our end's input
 #define PTY_BYTES_AVAILABLE TIOCOUTQ
 #elif defined(TIOCINQ)
