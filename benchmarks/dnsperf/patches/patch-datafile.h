$NetBSD: patch-datafile.h,v 1.1 2018/10/27 12:04:33 tron Exp $

Fix build with BIND 9.12.3 and newer

--- datafile.h.orig	2015-12-16 00:46:49.000000000 +0000
+++ datafile.h	2018-10-27 12:57:12.538706870 +0100
@@ -19,6 +19,10 @@
 #define PERF_DATAFILE_H 1
 
 #include <isc/types.h>
+#include <isc/boolean.h>
+#include <isc/int.h>
+
+#define ISC_PRINT_QUADFORMAT PRIu64
 
 typedef struct perf_datafile perf_datafile_t;
 
