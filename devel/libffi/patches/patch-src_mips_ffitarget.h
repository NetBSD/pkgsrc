$NetBSD: patch-src_mips_ffitarget.h,v 1.3 2025/04/10 09:47:49 adam Exp $

Make a minimal adjustment to support the various NetBSD mips ports.

--- src/mips/ffitarget.h.orig	2025-03-27 00:35:35.000000000 +0000
+++ src/mips/ffitarget.h
@@ -39,8 +39,10 @@
 #define _MIPS_SIM_ABI32		1
 #define _MIPS_SIM_NABI32	2
 #define _MIPS_SIM_ABI64		3
-#elif !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__linux__)
+#elif defined(__sgi)
 # include <sgidefs.h>
+#else
+# include <sys/cdefs.h>
 #endif
 
 #  ifndef _ABIN32
