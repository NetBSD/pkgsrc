$NetBSD$

64bit time_t workaround

--- base/logging.c.orig	2014-08-12 17:00:01.000000000 +0200
+++ base/logging.c	2016-02-07 21:57:26.000000000 +0100
@@ -184,7 +184,7 @@
 	strip(buffer);
 
 	/* write the buffer to the log file */
-	fprintf(fp, "[%lu] %s\n", log_time, buffer);
+	fprintf(fp, "[%lu] %s\n", (u_long)log_time, buffer);
 	fflush(fp);
 
 #ifdef USE_EVENT_BROKER
@@ -495,7 +495,7 @@
 
 	/* write the timestamp */
 	gettimeofday(&current_time, NULL);
-	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", current_time.tv_sec, current_time.tv_usec, level, verbosity, (unsigned long)getpid());
+	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_usec, level, verbosity, (unsigned long)getpid());
 
 	/* write the data */
 	va_start(ap, fmt);
