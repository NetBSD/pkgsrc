$NetBSD: patch-dyngen-exec.h,v 1.1 2012/09/13 14:38:19 adam Exp $

Register variables can't be global.

--- dyngen-exec.h.orig	2012-09-13 12:10:52.000000000 +0000
+++ dyngen-exec.h
@@ -61,7 +61,7 @@
 #endif
 
 #if defined(AREG0)
-register CPUArchState *env asm(AREG0);
+CPUArchState *env asm(AREG0);
 #else
 /* TODO: Try env = cpu_single_env. */
 extern CPUArchState *env;
