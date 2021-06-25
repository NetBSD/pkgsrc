$NetBSD: patch-lib_bch.c,v 1.1 2021/06/25 08:47:32 mrg Exp $

--- lib/bch.c.orig	2020-02-28 06:52:51.000000000 +0000
+++ lib/bch.c
@@ -62,7 +62,7 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
