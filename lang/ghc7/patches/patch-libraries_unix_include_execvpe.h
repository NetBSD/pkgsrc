$NetBSD: patch-libraries_unix_include_execvpe.h,v 1.1 2015/10/23 20:46:22 tnn Exp $

Don't conflict with builtin execvpe(3).

--- libraries/unix/include/execvpe.h.orig	2013-04-18 21:36:40.000000000 +0000
+++ libraries/unix/include/execvpe.h
@@ -19,7 +19,19 @@
 #endif
 
 #if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(_WIN32)
+#ifdef __NetBSD__
+#  include <sys/param.h>
+#  if __NetBSD_Version__ > 799000000
+#    define HAVE_EXECVPE 1
+#  endif
+#elif defined(__GLIBC__)
+#  define HAVE_EXECVPE 1
+#endif
+
+#ifdef HAVE_EXECVPE
+#include <unistd.h>
+#else
 extern int execvpe(char *name, char *const argv[], char **envp);
 extern void pPrPr_disableITimers (void);
+#endif /* HAVE_EXECVPE */
 #endif
-
