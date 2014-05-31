$NetBSD: patch-boehm-gc_mach__dep.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- boehm-gc/mach_dep.c.orig	2006-01-25 03:03:14.000000000 +0000
+++ boehm-gc/mach_dep.c
@@ -27,7 +27,7 @@
 #   endif
 # endif
 
-#if defined(RS6000) || defined(POWERPC)
+#if (defined(RS6000) || defined(POWERPC)) && !defined(OPENBSD)
 # include <ucontext.h>
 #endif
 
@@ -417,7 +417,7 @@ ptr_t arg;
         /* the stack.						*/
         __builtin_unwind_init();
 #     else /* !HAVE_BUILTIN_UNWIND_INIT */
-#      if defined(RS6000) || defined(POWERPC)
+#      if (defined(RS6000) || defined(POWERPC)) && !defined(OPENBSD)
 	/* FIXME: RS6000 means AIX.				*/
         /* This should probably be used in all Posix/non-gcc	*/
         /* settings.  We defer that change to minimize risk.	*/
