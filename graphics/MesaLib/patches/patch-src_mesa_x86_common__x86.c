$NetBSD: patch-src_mesa_x86_common__x86.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Treat NetBSD like OpenBSD.

--- src/mesa/x86/common_x86.c.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mesa/x86/common_x86.c
@@ -42,7 +42,7 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
-#if defined(USE_SSE_ASM) && defined(__OpenBSD__)
+#if defined(USE_SSE_ASM) && (defined(__OpenBSD__) || defined(__NetBSD__))
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <machine/cpu.h>
