$NetBSD: patch-gcc_ada_tracebak.c,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

Add NetBSD to some defines

--- gcc/ada/tracebak.c.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/tracebak.c
@@ -567,7 +567,7 @@
 /*------------------- aarch64 FreeBSD, Linux, RTEMS -----------------*/
 
 #elif (defined (__aarch64__) && (defined (__FreeBSD__) || \
-       defined (__linux__) || defined (__rtems__)))
+       defined (__linux__) || defined (__rtems__) || defined (__NetBSD__)))
 
 #define USE_GCC_UNWINDER
 #define PC_ADJUST -4
