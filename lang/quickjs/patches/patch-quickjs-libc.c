$NetBSD: patch-quickjs-libc.c,v 1.1 2019/11/14 21:20:04 rillig Exp $

Portability patch for NetBSD.

--- quickjs-libc.c.orig	2019-10-27 10:55:35.000000000 +0000
+++ quickjs-libc.c
@@ -1652,7 +1652,7 @@ static void os_signal_handler(int sig_nu
     os_pending_signals |= ((uint64_t)1 << sig_num);
 }
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__NetBSD__)
 typedef void (*sighandler_t)(int sig_num);
 #endif
 
