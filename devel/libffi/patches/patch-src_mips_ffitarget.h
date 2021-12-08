$NetBSD: patch-src_mips_ffitarget.h,v 1.2 2021/12/08 08:20:17 adam Exp $

Make a minimal adjustment to support the various NetBSD mips ports.

--- src/mips/ffitarget.h.orig	2021-06-27 15:17:08.000000000 +0000
+++ src/mips/ffitarget.h
@@ -41,8 +41,10 @@
 #define _MIPS_SIM_ABI32		1
 #define _MIPS_SIM_NABI32	2
 #define _MIPS_SIM_ABI64		3
-#elif !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#elif defined(__sgi)
 # include <sgidefs.h>
+#else
+# include <sys/cdefs.h>
 #endif
 
 #  ifndef _ABIN32
