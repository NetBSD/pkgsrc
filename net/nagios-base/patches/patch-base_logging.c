$NetBSD$

64bit time_t workaround

--- base/logging.c.orig	2017-05-09 19:03:31.000000000 +0200
+++ base/logging.c	2017-05-21 21:06:50.000000000 +0200
@@ -532,9 +532,9 @@
 		return ERROR;
 
 	/* write the timestamp */
 	gettimeofday(&current_time, NULL);
-	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", current_time.tv_sec, current_time.tv_usec, level, verbosity, (unsigned long)getpid());
+	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_usec, level, verbosity, (unsigned long)getpid());
 
 	/* write the data */
 	va_start(ap, fmt);
 	vfprintf(debug_file_fp, fmt, ap);
