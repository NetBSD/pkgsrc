$NetBSD: patch-src_des_conf-arm32-bsd.h,v 1.1 2017/10/08 02:41:39 sevan Exp $

- Add BSD on 32-BIT ARM support

--- src/des/conf-arm32-bsd.h.orig	2017-07-15 21:01:01.505692000 +0000
+++ src/des/conf-arm32-bsd.h
@@ -0,0 +1,5 @@
+#define NOASM
+#define BITS32
+#define BIG
+#define BSDUNIX
+#define LSBFIRST
