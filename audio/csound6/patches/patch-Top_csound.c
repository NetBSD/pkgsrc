$NetBSD: patch-Top_csound.c,v 1.3 2019/11/02 22:25:46 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Top/csound.c.orig	2019-07-12 14:54:19.000000000 -0700
+++ Top/csound.c	2019-10-29 13:50:02.540610805 -0700
@@ -1027,7 +1027,8 @@
 
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
-                         !defined(__MACH__) && !defined(__EMSCRIPTEN__))
+                         !defined(__MACH__) && !defined(__EMSCRIPTEN__) && \
+                         !defined(__NetBSD__) && defined(__DragonFly__))
 
 static char *signal_to_string(int sig)
 {
@@ -1226,7 +1227,7 @@
 }
 
 static const int sigs[] = {
-#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__)
+#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
   SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGIOT, SIGBUS,
   SIGFPE, SIGSEGV, SIGPIPE, SIGTERM, SIGXCPU, SIGXFSZ,
 #elif defined(WIN32)
