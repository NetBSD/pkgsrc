$NetBSD$

64-bit time_t workaround

Note: this file will fail the pkglint CVS ID check.  Fixing it in the repo will
cause other issues, so we just leave it as-is.  [sekiya@ 2022-01-09]

--- base/logging.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ base/logging.c	2023-01-09 06:59:17.162183952 +0900
@@ -533,7 +533,7 @@
 
 	/* write the timestamp */
 	gettimeofday(&current_time, NULL);
-	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", current_time.tv_sec, current_time.tv_usec, level, verbosity, (unsigned long)getpid());
+	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_usec, level, verbosity, (unsigned long)getpid());
 
 	/* write the data */
 	va_start(ap, fmt);
