$NetBSD: patch-src_lay_lay_laySignalHandler.cc,v 1.2 2020/10/30 15:35:11 mef Exp $

--- src/lay/lay/laySignalHandler.cc.orig	2020-10-25 01:23:18.681179164 +0000
+++ src/lay/lay/laySignalHandler.cc
@@ -450,7 +450,7 @@ void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
   act.sa_restorer = 0;
 #endif
 
