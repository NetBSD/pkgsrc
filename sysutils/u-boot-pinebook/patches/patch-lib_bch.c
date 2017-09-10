$NetBSD: patch-lib_bch.c,v 1.1 2017/09/10 17:00:41 jmcneill Exp $

--- lib/bch.c.orig	2017-07-10 17:07:38.000000000 +0000
+++ lib/bch.c
@@ -61,7 +61,7 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
