$NetBSD: patch-we__unix.c,v 1.1 2026/11/15 13:14:45 vins Exp $

Fix uncontiodional inclusion of execinfo.h. 

--- we_unix.c.orig
+++ we_unix.c
@@ -23,7 +23,23 @@
 #include <sys/wait.h>
 #include <dirent.h>
 #include <signal.h>
+/*
+ * configure looks for the backtrace() *library* (AC_SEARCH_LIBS) but never
+ * for the header, and nothing defines or tests HAVE_EXECINFO_H, so this
+ * include is unconditional.  On a system without execinfo.h the build stops
+ * here.  __has_include keeps the test in the source, where it does not need
+ * configure to be regenerated.
+ */
+#if defined(__has_include)
+# if __has_include(<execinfo.h>)
+#  define WPE_HAVE_EXECINFO 1
+# endif
+#elif defined(__GLIBC__)
+# define WPE_HAVE_EXECINFO 1
+#endif
+#ifdef WPE_HAVE_EXECINFO
 #include <execinfo.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <locale.h>
@@ -437,8 +453,12 @@
 
   len = snprintf(line, sizeof(line), "CRASH: signal %d\n", sig);
   write(fd, line, len);
+#ifdef WPE_HAVE_EXECINFO
   n = backtrace(bt, 32);
   backtrace_symbols_fd(bt, n, fd);
+#else
+  (void)bt; (void)n;
+#endif
   len = snprintf(line, sizeof(line), "MAXSLNS=%d MAXSCOL=%d\n", MAXSLNS, MAXSCOL);
   write(fd, line, len);
   close(fd);
