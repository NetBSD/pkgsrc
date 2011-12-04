$NetBSD: patch-unix-tlib.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/tlib.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/tlib.cxx
@@ -70,7 +70,7 @@
 #include <sys/mman.h>
 #endif
 
-#if defined(P_LINUX) || defined(P_SUN4) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_BEOS) || defined(P_IRIX) || defined(P_QNX)
+#if defined(P_LINUX) || defined(P_SUN4) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_BEOS) || defined(P_IRIX) || defined(P_QNX) || defined(P_DRAGONFLY)
 #include <sys/utsname.h>
 #define  HAS_UNAME
 #elif defined(P_RTEMS)
