$NetBSD: patch-lib_worker.c,v 1.1.2.3 2016/02/13 16:25:40 bsiegert Exp $

64bit time_t workaround
Workaround for poll(2) returning spurious POLLIN

--- lib/worker.c.orig	2014-08-12 17:00:01.000000000 +0200
+++ lib/worker.c	2016-02-08 12:31:57.000000000 +0100
@@ -194,7 +194,7 @@
 
 #define kvvec_add_tv(kvv, key, value) \
 	do { \
-		const char *buf = mkstr("%ld.%06ld", value.tv_sec, value.tv_usec); \
+		const char *buf = mkstr("%ld.%06ld", (unsigned long)value.tv_sec, (unsigned long)value.tv_usec); \
 		kvvec_addkv_wlen(kvv, key, sizeof(key) - 1, buf, strlen(buf)); \
 	} while (0)
 
@@ -439,6 +439,8 @@
 
 		rd = read(io->fd, buf, sizeof(buf));
 		if (rd < 0) {
+			if (!final && errno == EAGAIN)
+				return;
 			if (errno == EINTR || errno == EAGAIN)
 				continue;
 			if (!final && errno != EAGAIN)
