$NetBSD: patch-libasync.c,v 1.1 2015/07/13 14:05:56 ryoon Exp $

--- libasync.c.orig	2015-01-07 20:43:10.000000000 +0000
+++ libasync.c
@@ -96,7 +96,7 @@
 
 #include <sys/types.h>
 #include <aio.h>
-#if defined(solaris) || defined(linux) || defined(SCO_Unixware_gcc)
+#if defined(solaris) || defined(linux) || defined(SCO_Unixware_gcc) || defined(__NetBSD__)
 #else
 #include <sys/timers.h>
 #endif
@@ -119,7 +119,7 @@
 #include <stdlib.h>
 #endif
 
-#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(FreeBSD)
+#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(FreeBSD) || defined(__NetBSD__)
 /* If we are building for 64-bit Solaris, all functions that return pointers
  * must be declared before they are used; otherwise the compiler will assume
  * that they return ints and the top 32 bits of the pointer will be lost,
