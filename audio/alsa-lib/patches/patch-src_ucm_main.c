$NetBSD: patch-src_ucm_main.c,v 1.4 2026/01/08 09:16:32 wiz Exp $

fstat64 does not exist everywhere, fall back to fstat

--- src/ucm/main.c.orig	2025-12-19 10:31:58.000000000 +0000
+++ src/ucm/main.c
@@ -40,6 +40,10 @@
 #include <sys/wait.h>
 #include <limits.h>
 
+#ifndef CLOCK_MONOTONIC_RAW
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+#endif
+
 /*
  * misc
  */
@@ -176,6 +180,9 @@ static int read_tlv_file(unsigned int **res,
 		err = -errno;
 		goto __fail;
 	}
+#if !defined(fstat64) && !defined(__linux__) && !defined(__illumos__)
+#define fstat64 fstat
+#endif
 	if (fstat64(fd, &st) == -1) {
 		err = -errno;
 		goto __fail;
