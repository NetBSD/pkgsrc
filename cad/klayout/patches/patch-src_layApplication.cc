$NetBSD: patch-src_layApplication.cc,v 1.1 2016/03/15 15:15:59 mef Exp $

To avoid following message
error: 'struct sigaction' has no member named 'sa_restorer'

--- src/layApplication.cc.orig	2016-02-27 07:20:30.000000000 +0900
+++ src/layApplication.cc	2016-03-08 23:52:13.000000000 +0900
@@ -349,7 +349,7 @@ static void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__NetBSD__)
   act.sa_restorer = 0;
 #endif
 
