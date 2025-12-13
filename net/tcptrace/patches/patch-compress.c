$NetBSD: patch-compress.c,v 1.1 2025/12/13 16:42:03 vins Exp $

--- compress.c.orig	2004-10-01 21:42:34.000000000 +0000
+++ compress.c
@@ -61,6 +61,12 @@ static char const GCC_UNUSED rcsid[] =
 
 #include "compress.h"
 #include <sys/wait.h>
+#ifdef __linux__
+#include <stdio.h>
+#include <stdio_ext.h>
+#else
+#include <stdio.h>
+#endif
 
 /*
  * OK, this stuff is a little complicated.  Here's why:
@@ -240,7 +246,11 @@ CompReopenFile(
     /* erase the file buffer and reposition to the front */
 #ifdef HAVE_FPURGE
     /* needed for NetBSD and FreeBSD (at least) */
+# if defined(__linux__)
+    __fpurge(stdin);		/* discard input buffer */
+# else
     fpurge(stdin);		/* discard input buffer */
+# endif
 #else /* HAVE_FPURGE */
     fflush(stdin);		/* discard input buffer */
 #endif /* HAVE_FPURGE */
@@ -598,8 +608,12 @@ PipeHelper(void)
     // Now, we shall purge our old STDIN stream buffer, and point it to the
     // read end of the pipe, fdpipe[0]
     
-#ifdef HAVE_FPURGE     
-     fpurge(stdin); // needed for NetBSD/FreeBSD
+#ifdef HAVE_FPURGE
+# if defined(__linux__)
+    __fpurge(stdin);
+# else
+    fpurge(stdin);
+# endif
 #else
      fflush(stdin);
 #endif
