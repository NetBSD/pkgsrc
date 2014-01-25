$NetBSD: patch-boehm-gc_include_gc__config__macros.h,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/include/gc_config_macros.h.orig	2012-02-10 16:32:36.000000000 +0000
+++ boehm-gc/include/gc_config_macros.h
@@ -20,7 +20,7 @@
 	defined(GC_IRIX_THREADS) || defined(GC_LINUX_THREADS) || \
 	defined(GC_HPUX_THREADS) || defined(GC_OSF1_THREADS) || \
 	defined(GC_DGUX386_THREADS) || defined(GC_DARWIN_THREADS) || \
-	defined(GC_AIX_THREADS) || \
+	defined(GC_AIX_THREADS) || defined(GC_OPENBSD_THREADS) || \
         (defined(GC_WIN32_THREADS) && defined(__CYGWIN32__))
 #   define GC_PTHREADS
 # endif
@@ -55,6 +55,10 @@
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
