$NetBSD: patch-src_ucm_main.c,v 1.3 2025/07/10 14:41:01 jperkin Exp $

fstat64 does not exist everywhere, fall back to fstat

--- src/ucm/main.c.orig	2025-04-14 16:42:04.000000000 +0000
+++ src/ucm/main.c
@@ -176,6 +176,9 @@ static int read_tlv_file(unsigned int **
 		err = -errno;
 		return err;
 	}
+#if !defined(fstat64) && !defined(__linux__) && !defined(__illumos__)
+#define fstat64 fstat
+#endif
 	if (fstat64(fd, &st) == -1) {
 		err = -errno;
 		goto __fail;
