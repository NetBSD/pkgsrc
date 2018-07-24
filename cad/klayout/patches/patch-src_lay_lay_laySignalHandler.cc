$NetBSD: patch-src_lay_lay_laySignalHandler.cc,v 1.1 2018/07/24 13:00:10 ryoon Exp $

--- src/lay/lay/laySignalHandler.cc.orig	2018-05-04 19:21:14.000000000 +0000
+++ src/lay/lay/laySignalHandler.cc
@@ -450,7 +450,7 @@ void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__NetBSD__)
   act.sa_restorer = 0;
 #endif
 
