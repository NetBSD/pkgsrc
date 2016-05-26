$NetBSD: patch-src_kptydevice.cpp,v 1.1 2016/05/26 08:29:06 markd Exp $

NetBSD like FreeBSD

--- src/kptydevice.cpp.orig	2016-04-03 21:01:19.000000000 +0000
+++ src/kptydevice.cpp
@@ -43,7 +43,7 @@
 # include <sys/time.h>
 #endif
 
-#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 // "the other end's output queue size" - kinda braindead, huh?
 # define PTY_BYTES_AVAILABLE TIOCOUTQ
 #elif defined(TIOCINQ)
