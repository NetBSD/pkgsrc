$NetBSD: patch-unix-switch.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/switch.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/switch.cxx
@@ -54,7 +54,7 @@
 #endif
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD)  || defined(P_NETBSD)
+#if defined(P_FREEBSD) || defined(P_OPENBSD)  || defined(P_NETBSD) || defined(P_DRAGONFLY)
 #define	SET_STACK	context[0]._jb[2] = (int)stackTop-16;
 #if defined(P_NETBSD)
 #include <sys/mman.h>
