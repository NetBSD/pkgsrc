$NetBSD: patch-main.c,v 1.1 2025/12/18 17:49:04 nia Exp $

Fix build on SunOS.

--- main.c.orig	2025-12-18 17:25:13.163086186 +0000
+++ main.c
@@ -52,7 +52,7 @@ void bench(double *b)
 }
 
 #ifndef WIN32
-#include <sys/signal.h>
+#include <signal.h>
 #endif
 volatile D0_BOOL quit = 0;
 void mysignal(int signo)
