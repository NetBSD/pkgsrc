$NetBSD: patch-src_ucm_main.c,v 1.2 2024/08/05 11:55:10 tnn Exp $

fstat64 does not exist everywhere, fall back to fstat

--- src/ucm/main.c.orig	2024-06-10 09:18:34.000000000 +0000
+++ src/ucm/main.c
@@ -176,6 +176,9 @@ static int read_tlv_file(unsigned int **
 		err = -errno;
 		return err;
 	}
+#if !defined(fstat64) && !defined(__linux__)
+#define fstat64 fstat
+#endif
 	if (fstat64(fd, &st) == -1) {
 		err = -errno;
 		goto __fail;
