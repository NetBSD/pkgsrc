$NetBSD: patch-boehm-gc_include_gc__config__macros.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- boehm-gc/include/gc_config_macros.h.orig	2012-11-04 22:56:02.000000000 +0000
+++ boehm-gc/include/gc_config_macros.h
@@ -22,7 +22,7 @@
 	defined(GC_GNU_THREADS) || \
 	defined(GC_HPUX_THREADS) || defined(GC_OSF1_THREADS) || \
 	defined(GC_DGUX386_THREADS) || defined(GC_DARWIN_THREADS) || \
-	defined(GC_AIX_THREADS) || \
+	defined(GC_AIX_THREADS) || defined(GC_OPENBSD_THREADS) || \
         (defined(GC_WIN32_THREADS) && defined(__CYGWIN32__))
 #   define GC_PTHREADS
 # endif
@@ -57,6 +57,10 @@
 #   define GC_FREEBSD_THREADS
 #   define GC_PTHREADS
 # endif
+# if !defined(GC_PTHREADS) && defined(__OpenBSD__)
+#   define GC_OPENBSD_THREADS
+#   define GC_PTHREADS
+# endif
 # if defined(DGUX) && (defined(i386) || defined(__i386__))
 #   define GC_DGUX386_THREADS
 #   define GC_PTHREADS
