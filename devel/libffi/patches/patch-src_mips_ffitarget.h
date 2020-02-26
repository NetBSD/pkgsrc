$NetBSD: patch-src_mips_ffitarget.h,v 1.1 2020/02/26 19:15:44 adam Exp $

Make a minimal adjustment to support the various NetBSD mips ports.

--- src/mips/ffitarget.h.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/mips/ffitarget.h
@@ -41,8 +41,10 @@
 #define _MIPS_SIM_ABI32		1
 #define _MIPS_SIM_NABI32	2
 #define _MIPS_SIM_ABI64		3
-#elif !defined(__OpenBSD__)
+#elif defined(__sgi)
 # include <sgidefs.h>
+#else
+# include <sys/cdefs.h>
 #endif
 
 #  ifndef _ABIN32
