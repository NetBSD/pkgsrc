$NetBSD: patch-include_u.h,v 1.1 2015/04/25 19:58:32 dholland Exp $

Add support for modern BSDs.

--- include/u.h.orig	2000-02-11 17:05:58.000000000 +0000
+++ include/u.h
@@ -189,6 +189,28 @@ typedef unsigned long long uvlong;
 typedef long long vlong;
 #endif
 
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#define _XOPEN_SOURCE_EXTENDED
+
+#include <stdarg.h>
+#include <setjmp.h>
+#include <string.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <errno.h>
+#include <math.h>
+#include <fcntl.h>
+#include <sys/wait.h>
+#include <sys/types.h>
+#include <time.h>
+#include <sys/resource.h>
+
+typedef unsigned char uchar;
+typedef unsigned long ulong;
+typedef unsigned long long uvlong;
+typedef long long vlong;
+#endif
+
 #ifdef sgi
 #include <stdarg.h>
 #include <setjmp.h>
