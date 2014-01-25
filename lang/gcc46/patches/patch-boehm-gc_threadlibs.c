$NetBSD: patch-boehm-gc_threadlibs.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/threadlibs.c.orig	2006-01-25 03:03:14.000000000 +0000
+++ boehm-gc/threadlibs.c
@@ -15,6 +15,9 @@ int main()
 	|| defined(GC_DARWIN_THREADS) || defined(GC_AIX_THREADS)
         printf("-lpthread\n");
 #   endif
+#   if defined(GC_OPENBSD_THREADS)
+	printf("-pthread\n");
+#   endif
 #   if defined(GC_FREEBSD_THREADS)
 #       if (__FREEBSD_version >= 500000)
           printf("-lpthread\n");
