$NetBSD: patch-Top_csound.c,v 1.2 2014/08/05 05:12:38 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Top/csound.c.orig	2014-01-07 08:54:20.000000000 -0800
+++ Top/csound.c	2014-02-12 23:44:07.000000000 -0800
@@ -900,7 +900,8 @@
 
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
-                         !defined(__MACH__))
+                         !defined(__MACH__) && !defined(__NetBSD__) && \
+			 !defined(__DragonFly__))
 static char *signal_to_string(int sig)
 {
     switch(sig) {
@@ -1053,7 +1054,7 @@
 }
 
 static const int sigs[] = {
-#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__)
+#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
   SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGIOT, SIGBUS,
   SIGFPE, SIGSEGV, SIGPIPE, SIGTERM, SIGXCPU, SIGXFSZ,
 #elif defined(WIN32)
