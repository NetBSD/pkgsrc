$NetBSD: patch-lib_test-squeue.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- lib/test-squeue.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ lib/test-squeue.c	2023-01-09 07:15:59.004620782 +0900
@@ -50,7 +50,7 @@
 
 	walks++;
 	t(sq_high <= evt->when.tv_sec, "sq_high: %lu; evt->when: %lu\n",
-	  sq_high, evt->when.tv_sec);
+	  sq_high, (unsigned long)evt->when.tv_sec);
 	sq_high = (unsigned long)evt->when.tv_sec;
 
 	return 0;
