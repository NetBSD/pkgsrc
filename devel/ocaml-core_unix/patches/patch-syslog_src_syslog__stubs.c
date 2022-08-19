$NetBSD: patch-syslog_src_syslog__stubs.c,v 1.1 2022/08/19 12:42:34 tnn Exp $

LOG_PERROR not present on SunOS

--- syslog/src/syslog_stubs.c.orig	2022-02-15 14:18:18.000000000 +0000
+++ syslog/src/syslog_stubs.c
@@ -8,6 +8,9 @@
 
 #include "ocaml_utils.h"
 
+#ifndef LOG_PERROR
+#define LOG_PERROR 0
+#endif
 static int log_open_options[] = {
   /* THESE MUST STAY IN THE SAME ORDER AS IN syslog.ml!!! */
   LOG_PID, LOG_CONS, LOG_ODELAY, LOG_NDELAY, LOG_NOWAIT, LOG_PERROR
