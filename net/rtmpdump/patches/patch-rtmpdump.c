$NetBSD: patch-rtmpdump.c,v 1.1 2020/11/29 22:03:12 dbj Exp $

On MacOS with clang 12.0.0 we get an undefined symbol
error for CleanupSockets().  Presumably the inline is
getting optimized away.  Work around this by using the
same #define as the other sources in this directory.

--- rtmpdump.c.orig	2018-09-23 10:40:58.000000000 +0000
+++ rtmpdump.c
@@ -67,13 +67,11 @@ InitSockets()
 #endif
 }
 
-inline void
-CleanupSockets()
-{
 #ifdef WIN32
-  WSACleanup();
+#define	CleanupSockets()	WSACleanup()
+#else
+#define	CleanupSockets()
 #endif
-}
 
 #ifdef _DEBUG
 uint32_t debugTS = 0;
