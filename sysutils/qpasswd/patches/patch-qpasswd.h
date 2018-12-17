$NetBSD: patch-qpasswd.h,v 1.2 2018/12/17 16:32:19 schmonz Exp $

Avoid Linuxisms. Handle _XOPEN_SOURCE on SunOS.

--- qpasswd.h.orig	2004-01-13 16:10:18.000000000 +0000
+++ qpasswd.h
@@ -1,21 +1,28 @@
 #ifndef QP_QPASSWD_H
 #define QP_QPASSWD_H
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE 500
+#  else
+#define _XOPEN_SOURCE 600
+#  endif
+#else
 #define _XOPEN_SOURCE  /* needed for crypt(3) */
+#endif
 #define _BSD_SOURCE    /* needed by initgroups(3) + fchdir(2) */
 
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #include <signal.h>
-#include <shadow.h>
 #include <string.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <errno.h>
-#include <wait.h>
 #include <time.h>
 #include <grp.h>
 #include <pwd.h>
