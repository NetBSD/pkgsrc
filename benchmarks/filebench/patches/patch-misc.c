$NetBSD: patch-misc.c,v 1.1.1.1 2012/07/02 17:43:16 asau Exp $

--- misc.c.orig	2011-09-06 17:17:45.000000000 +0000
+++ misc.c
@@ -312,13 +312,13 @@ fatal:
 
 	} else if (filebench_shm->shm_debug_level > LOG_INFO) {
 		if (level < LOG_INFO)
-#ifdef HAVE_PROC_PID_STAT
+#if HAVE_GETTID
 			(void) fprintf(stderr, "%5d: ", (int)gettid());
 #else
 			(void) fprintf(stderr, "%5d: ", (int)my_pid);
 #endif
 		else
-#ifdef HAVE_PROC_PID_STAT
+#if HAVE_GETTID
 			(void) fprintf(stdout, "%5d: ", (int)gettid());
 #else
 			(void) fprintf(stdout, "%5d: ", (int)my_pid);
