$NetBSD: patch-boehm-gc_threadlibs.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- boehm-gc/threadlibs.c.orig	2012-11-04 22:56:02.000000000 +0000
+++ boehm-gc/threadlibs.c
@@ -16,6 +16,9 @@ int main()
 	|| defined(GC_GNU_THREADS)
         printf("-lpthread\n");
 #   endif
+#   if defined(GC_OPENBSD_THREADS)
+	printf("-pthread\n");
+#   endif
 #   if defined(GC_FREEBSD_THREADS)
 #       if (__FREEBSD_version >= 500000)
           printf("-lpthread\n");
