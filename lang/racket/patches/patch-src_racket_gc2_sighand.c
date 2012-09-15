$NetBSD: patch-src_racket_gc2_sighand.c,v 1.1 2012/09/15 13:33:59 marino Exp $

Add DragonFly support.

--- src/racket/gc2/sighand.c.orig	2012-08-06 22:51:46.000000000 +0000
+++ src/racket/gc2/sighand.c
@@ -125,7 +125,11 @@ void fault_handler(int sn, struct siginf
 
 /* ========== FreeBSD/NetBSD/OpenBSD signal handler ========== */
 /*  As of 2007/06/29, this is a guess for NetBSD!  */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) \
+ || defined(__FreeBSD_kernel__) \
+ || defined(__NetBSD__) \
+ || defined(__OpenBSD__) \
+ || defined(__DragonFly__)
 # include <signal.h>
 # include <sys/param.h>
 void fault_handler(int sn, siginfo_t *si, void *ctx)
