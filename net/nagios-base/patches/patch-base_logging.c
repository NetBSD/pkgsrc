$NetBSD$

64bit time_t workaround

--- base/logging.c.orig	2016-02-07 13:23:57.000000000 +0100
+++ base/logging.c	2016-02-07 13:24:50.000000000 +0100
@@ -184,7 +184,7 @@
 	strip(buffer);
 
 	/* write the buffer to the log file */
-	fprintf(fp, "[%lu] %s\n", log_time, buffer);
+	fprintf(fp, "[%lu] %s\n", (u_long)log_time, buffer);
 	fflush(fp);
 
 #ifdef USE_EVENT_BROKER
