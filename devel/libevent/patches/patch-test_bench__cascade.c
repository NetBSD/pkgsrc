$NetBSD: patch-test_bench__cascade.c,v 1.1 2017/09/22 02:58:50 maya Exp $

Remove redundant include (absent in QNX 6.5)

--- test/bench_cascade.c.orig	2016-10-04 19:55:31.000000000 +0000
+++ test/bench_cascade.c
@@ -48,7 +48,6 @@
 #include <unistd.h>
 #endif
 #include <errno.h>
-#include <getopt.h>
 #include <event.h>
 #include <evutil.h>
 
