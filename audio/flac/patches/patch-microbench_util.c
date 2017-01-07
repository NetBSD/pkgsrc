$NetBSD: patch-microbench_util.c,v 1.1 2017/01/07 10:26:54 adam Exp $

Fix building on systems where CLOCK_PROCESS_CPUTIME_ID is not defined.

--- microbench/util.c.orig	2017-01-07 10:24:50.000000000 +0000
+++ microbench/util.c
@@ -95,7 +95,7 @@ benchmark_function (void (*testfunc) (vo
 	return counter_diff (&start, &end) / count ;
 } /* benchmark_function */
 
-#elif defined HAVE_CLOCK_GETTIME
+#elif defined HAVE_CLOCK_GETTIME && defined CLOCK_PROCESS_CPUTIME_ID
 
 #include <time.h>
 #include <sys/time.h>
