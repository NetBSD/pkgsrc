$NetBSD: patch-lib_test-squeue.c,v 1.2 2016/02/09 10:12:53 bouyer Exp $

64bit time_t workaround

--- lib/test-squeue.c.orig	2016-02-07 21:16:30.000000000 +0100
+++ lib/test-squeue.c	2016-02-07 21:17:02.000000000 +0100
@@ -50,7 +50,7 @@
 
 	walks++;
 	t(sq_high <= evt->when.tv_sec, "sq_high: %lu; evt->when: %lu\n",
-	  sq_high, evt->when.tv_sec);
+	  sq_high, (unsigned long)evt->when.tv_sec);
 	sq_high = (unsigned long)evt->when.tv_sec;
 
 	return 0;
