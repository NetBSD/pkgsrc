$NetBSD: patch-boehm-gc_tests_test.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/tests/test.c.orig	2010-12-10 10:09:10.000000000 +0000
+++ boehm-gc/tests/test.c
@@ -1804,7 +1804,8 @@ main()
 
     pthread_attr_init(&attr);
 #   if defined(GC_IRIX_THREADS) || defined(GC_FREEBSD_THREADS) \
-    	|| defined(GC_DARWIN_THREADS) || defined(GC_AIX_THREADS)
+    	|| defined(GC_DARWIN_THREADS) || defined(GC_AIX_THREADS) \
+	|| defined(GC_OPENBSD_THREADS)
     	pthread_attr_setstacksize(&attr, 1000000);
 #   endif
     n_tests = 0;
