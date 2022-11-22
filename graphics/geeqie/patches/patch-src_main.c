$NetBSD: patch-src_main.c,v 1.1 2022/11/22 14:13:23 gdt Exp $

Avoid UB in a signal handler, and avoid making an mmap call that POSIX says must fail.

Filed upstream:
  https://github.com/BestImageViewer/geeqie/issues/1052
  https://github.com/BestImageViewer/geeqie/pull/1053

--- src/main.c.orig	2022-08-12 09:32:26.000000000 +0000
+++ src/main.c
@@ -1016,22 +1016,31 @@ void exit_program(void)
 	exit_program_final();
 }
 
-/* This code is supposed to handle situation when a file mmaped by image_loader
+/* This code attempts to handle situation when a file mmaped by image_loader
  * or by exif loader is truncated by some other process.
- * This is probably not completely correct according to posix, because
- * mmap is not in the list of calls that can be used safely in signal handler,
- * but anyway, the handler is called in situation when the application would
- * crash otherwise.
- * Ideas for improvement are welcome ;)
+ * This code is incorrect according to POSIX, because:
+ *
+ *   mmap is not async-signal-safe and thus may not be called from a signal handler
+ * 
+ *   mmap must be called with a valid file descriptor.  POSIX requires that
+ *   a fildes argument of -1 must cause mmap to return EBADF.
+ *
+ * See https://github.com/BestImageViewer/geeqie/issues/1052 for discussion of
+ * an alternative approach.
  */
 /** @FIXME this probably needs some better ifdefs. Please report any compilation problems */
 
 #if defined(SIGBUS) && defined(SA_SIGINFO)
 static void sigbus_handler_cb(int UNUSED(signum), siginfo_t *info, void *UNUSED(context))
 {
-	unsigned long pagesize = sysconf(_SC_PAGE_SIZE);
-	DEBUG_1("SIGBUS %p", info->si_addr);
-	mmap((void *)(((unsigned long)info->si_addr / pagesize) * pagesize), pagesize, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
+	/*
+	 * @FIXME Design and implement a POSIX-acceptable approach,
+	 * after first documenting the sitations where SIGBUS occurs.
+	 * See https://github.com/BestImageViewer/geeqie/issues/1052 for discussion
+	 */
+
+	DEBUG_1("SIGBUS %p NOT HANDLED", info->si_addr);
+	exit(-1);
 }
 #endif
 
@@ -1204,7 +1213,10 @@ gint main(gint argc, gchar *argv[])
 	/* setup random seed for random slideshow */
 	srand(time(NULL));
 
+#if 0
+	/* See later comment; this handler leads to UB. */
 	setup_sigbus_handler();
+#endif
 
 	/* register global notify functions */
 	file_data_register_notify_func(cache_notify_cb, NULL, NOTIFY_PRIORITY_HIGH);
