$NetBSD: patch-boehm-gc_misc.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- boehm-gc/misc.c.orig	2006-09-14 18:06:04.000000000 +0000
+++ boehm-gc/misc.c
@@ -660,7 +660,7 @@ void GC_init_inner()
 #   if defined(SEARCH_FOR_DATA_START)
 	GC_init_linux_data_start();
 #   endif
-#   if (defined(NETBSD) || defined(OPENBSD)) && defined(__ELF__)
+#   if defined(NETBSD) && defined(__ELF__)
 	GC_init_netbsd_elf();
 #   endif
 #   if defined(GC_PTHREADS) || defined(GC_SOLARIS_THREADS) \
