$NetBSD: patch-os.h,v 1.1 2018/10/27 12:04:33 tron Exp $

Fix build with BIND 9.12.3 and newer

--- os.h.orig	2015-12-16 00:46:50.000000000 +0000
+++ os.h	2018-10-27 12:59:42.370351276 +0100
@@ -18,6 +18,9 @@
 #ifndef PERF_OS_H
 #define PERF_OS_H 1
 
+#include <isc/boolean.h>
+#include <isc/int.h>
+
 void
 perf_os_blocksignal(int sig, isc_boolean_t block);
 
