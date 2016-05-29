$NetBSD: patch-tempfile.c,v 1.1.1.1 2016/05/29 22:24:33 abs Exp $

-- Handle the non Linux case by just wrapping tmpfile()
-- (which may be secure on some of those systems :)

--- tempfile.c.orig	2016-05-13 05:18:32.000000000 +0000
+++ tempfile.c
@@ -17,16 +17,20 @@
 
 #include <paths.h>
 #include <fcntl.h>		/* O_TMPFILE requires -D_GNU_SOURCE */
+#ifdef __linux__ 
 #include <linux/version.h>
+#endif
 #include <stdlib.h>		/* mkstemp() */
 #include <stdio.h>		/* fdopen() */
 #include <sys/stat.h>		/* umask() */
 
+#ifdef __linux__ 
 #ifndef  O_TMPFILE		/* Too old GLIBC or kernel */
 #warning O_TMPFILE missing on your system, tempfile() may not work!
 #define  __O_TMPFILE 020000000
 #define  O_TMPFILE (__O_TMPFILE | O_DIRECTORY) /* Define and let it fail at runtime */
 #endif
+#endif
 
 /**
  * tempfile - A secure tmpfile() replacement
@@ -43,6 +47,10 @@
  */
 FILE *tempfile(void)
 {
+#ifndef __linux__
+#warning Not on Linux, reverting to wrap tmpfile(), which may or may not be safe ...
+	return tmpfile();
+#else
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)
 	int fd;
 	mode_t oldmask;
@@ -58,6 +66,7 @@ FILE *tempfile(void)
 #warning Too old kernel, reverting to wrap unsafe tmpfile() ...
 	return tmpfile();
 #endif
+#endif
 }
 
 #ifdef UNITTEST
