$NetBSD: patch-lib_worker.c,v 1.1 2016/02/07 21:52:06 bouyer Exp $

64bit time_t workaround

--- lib/worker.c.orig	2014-08-12 17:00:01.000000000 +0200
+++ lib/worker.c	2016-02-07 22:08:53.000000000 +0100
@@ -194,7 +194,7 @@
 
 #define kvvec_add_tv(kvv, key, value) \
 	do { \
-		const char *buf = mkstr("%ld.%06ld", value.tv_sec, value.tv_usec); \
+		const char *buf = mkstr("%ld.%06ld", (unsigned long)value.tv_sec, (unsigned long)value.tv_usec); \
 		kvvec_addkv_wlen(kvv, key, sizeof(key) - 1, buf, strlen(buf)); \
 	} while (0)
 
