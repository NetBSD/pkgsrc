$NetBSD: patch-src_error.c,v 1.1 2017/03/31 15:15:22 jakllsch Exp $

Use LOG_ERR instead of LOG_EMERG, as LOG_EMERG causes syslogd to tell all
ttys.

--- src/error.c.orig	2005-06-03 16:06:07.000000000 +0000
+++ src/error.c
@@ -208,7 +208,7 @@ memerror:
      *   with the message here.
      */
 #if HAVE_SYSLOG_H
-    syslog (LOG_DAEMON | LOG_EMERG, "Memory exhausted.  Aborting.");
+    syslog (LOG_DAEMON | LOG_ERR, "Memory exhausted.  Aborting.");
 #endif /* HAVE_SYSLOG_H */
 
     goto sidestep_done;
@@ -219,18 +219,18 @@ recursion_error:
      * error while attempting to send the last error message to the client.
      */
 
-    syslog (LOG_DAEMON | LOG_EMERG,
+    syslog (LOG_DAEMON | LOG_ERR,
 	    "error (%d, %d) called recursively.  Original message was:",
 	    last_status, last_errnum);
-    syslog (LOG_DAEMON | LOG_EMERG, "%s", last_message);
+    syslog (LOG_DAEMON | LOG_ERR, "%s", last_message);
 
 
-    syslog (LOG_DAEMON | LOG_EMERG,
+    syslog (LOG_DAEMON | LOG_ERR,
             "error (%d, %d) called recursively.  Second message was:",
 	    status, errnum);
-    syslog (LOG_DAEMON | LOG_EMERG, "%s", buf2);
+    syslog (LOG_DAEMON | LOG_ERR, "%s", buf2);
 
-    syslog (LOG_DAEMON | LOG_EMERG, "Aborting.");
+    syslog (LOG_DAEMON | LOG_ERR, "Aborting.");
 #endif /* HAVE_SYSLOG_H */
 
 sidestep_done:
