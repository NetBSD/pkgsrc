$NetBSD: patch-src_cares__wrap.h,v 1.1 2021/05/21 06:56:29 adam Exp $

NetBSD has no AI_V4MAPPED.

--- src/cares_wrap.h.orig	2021-05-20 17:49:34.000000000 +0000
+++ src/cares_wrap.h
@@ -36,7 +36,8 @@
 #  define T_CAA    257 /* Certification Authority Authorization */
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+# define AI_ALL 0
 # define AI_V4MAPPED 0
 #endif
 
