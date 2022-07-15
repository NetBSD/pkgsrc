$NetBSD: patch-src_ucm_main.c,v 1.1 2022/07/15 21:17:25 wiz Exp $

fstat64 does not exist everywhere, fall back to fstat

--- src/ucm/main.c.orig	2022-06-17 09:42:05.000000000 +0000
+++ src/ucm/main.c
@@ -176,6 +176,9 @@ static int read_tlv_file(unsigned int **
 		err = -errno;
 		return err;
 	}
+#ifndef fstat64
+#define fstat64 fstat
+#endif
 	if (fstat64(fd, &st) == -1) {
 		err = -errno;
 		goto __fail;
