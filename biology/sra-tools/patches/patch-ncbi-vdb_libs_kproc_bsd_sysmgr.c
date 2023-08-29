$NetBSD: patch-ncbi-vdb_libs_kproc_bsd_sysmgr.c,v 1.1 2023/08/29 00:00:25 bacon Exp $

# Add NetBSD pthread_main_np() stand-in

--- ncbi-vdb/libs/kproc/bsd/sysmgr.c.orig	2023-08-15 12:41:59.000000000 +0000
+++ ncbi-vdb/libs/kproc/bsd/sysmgr.c
@@ -30,6 +30,23 @@
 #include <pthread.h>
 #include <unistd.h>
 
+/*
+ * NetBSD lacks non-POSIX POSIX threads functions (pthread_np)
+ */
+
+#ifdef __NetBSD__
+
+// This should be initialized to pthread_self() at the start of main()
+// If the thread ID of this thread is the same, then this is the main thread
+pthread_t _ncbi_thr_main;
+
+int	pthread_main_np(void)
+
+{
+    return pthread_equal(pthread_self(), _ncbi_thr_main);
+}
+#endif
+
 /* OnMainThread
  *  returns true if running on main thread
  */
