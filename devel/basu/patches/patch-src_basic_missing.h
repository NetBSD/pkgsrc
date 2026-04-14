$NetBSD: patch-src_basic_missing.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Define unknown errnos

--- src/basic/missing.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/missing.h
@@ -70,10 +70,24 @@
 #define TASK_COMM_LEN 16
 #endif
 
-#ifdef __FreeBSD__
+#include <errno.h>
+
+#ifndef ENOMEDIUM
 #define ENOMEDIUM       (INT_MAX - 1)
+#endif
+
+#ifndef ENOPKG
 #define ENOPKG          (INT_MAX - 2)
+#endif
+
+#ifndef EUNATCH
 #define EUNATCH         (INT_MAX - 3)
+#endif
+
+#ifndef ENODATA
 #define ENODATA         (INT_MAX - 4)
+#endif
+
+#ifndef ELNRNG
 #define ELNRNG          (INT_MAX - 5)
 #endif
