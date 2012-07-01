$NetBSD: patch-dhry.h,v 1.1 2012/07/01 10:13:04 sbd Exp $

If the obsolete CLK_TCK isn't defined use CLOCKS_PER_SEC.

--- dhry.h.orig	1988-07-12 19:35:09.000000000 +0000
+++ dhry.h
@@ -362,6 +362,9 @@
 #undef HZ
 #undef TIMES
 #include <time.h>
+#ifndef CLK_TCK
+#define CLK_TCK CLOCKS_PER_SEC
+#endif
 #define HZ	CLK_TCK
 #endif
 		/* Use Microsoft C hi-res clock */
