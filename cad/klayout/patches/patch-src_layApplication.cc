$NetBSD: patch-src_layApplication.cc,v 1.2 2017/02/14 21:33:08 joerg Exp $

To avoid following message
error: 'struct sigaction' has no member named 'sa_restorer'

--- src/layApplication.cc.orig	2016-11-27 22:52:20.000000000 +0000
+++ src/layApplication.cc
@@ -69,6 +69,7 @@
 #  include <execinfo.h>
 #endif
 
+#include <unistd.h>
 #include <iostream>
 #include <memory>
 #include <algorithm>
@@ -350,7 +351,7 @@ static void install_signal_handlers ()
   act.sa_sigaction = signal_handler;
   sigemptyset (&act.sa_mask);
   act.sa_flags = SA_SIGINFO;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__NetBSD__)
   act.sa_restorer = 0;
 #endif
 
