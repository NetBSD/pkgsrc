$NetBSD: patch-src_util_stopwatch.h,v 1.1 2018/03/13 00:31:16 khorben Exp $

--- src/util/stopwatch.h.orig	2016-11-07 22:02:30.000000000 +0000
+++ src/util/stopwatch.h
@@ -130,6 +130,11 @@ public:
 
 #include<ctime>
 
+#ifndef CLOCK_PROCESS_CPUTIME_ID
+/* BSD */
+# define CLOCK_PROCESS_CPUTIME_ID CLOCK_MONOTONIC
+#endif
+
 class stopwatch {
     unsigned long long m_time; // elapsed time in ns
     bool               m_running;
