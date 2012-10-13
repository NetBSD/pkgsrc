$NetBSD: patch-unix-tlib.cxx,v 1.2 2012/10/13 00:49:39 darcy Exp $

- Add DragonFly support

--- src/ptlib/unix/tlib.cxx.orig	2012-08-23 02:12:27.000000000 +0000
+++ src/ptlib/unix/tlib.cxx
@@ -70,7 +70,7 @@
 #include <sys/mman.h>
 #endif
 
-#if defined(P_LINUX) || defined(P_SUN4) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_BEOS) || defined(P_IRIX) || defined(P_QNX) || defined(P_GNU_HURD)
+#if defined(P_LINUX) || defined(P_SUN4) || defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_BEOS) || defined(P_IRIX) || defined(P_QNX) || defined(P_GNU_HURD) || defined(P_DRAGONFLY)
 #include <sys/utsname.h>
 #define  HAS_UNAME
 #elif defined(P_RTEMS)
