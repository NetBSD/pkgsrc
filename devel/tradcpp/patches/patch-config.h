$NetBSD: patch-config.h,v 1.1 2016/12/16 18:30:58 dholland Exp $

Recognize __ia64__. (from upstream tree)

--- config.h.orig	2016-09-04 21:16:39.000000000 +0000
+++ config.h
@@ -124,6 +124,8 @@
 #define CONFIG_CPU "__ppc64__"
 #elif defined(__ARM__)
 #define CONFIG_CPU "__ARM__"
+#elif defined(__ia64__)
+#define CONFIG_CPU "__ia64__"
 #else
 /* let it go */
 #endif
