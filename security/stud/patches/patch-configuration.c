$NetBSD: patch-configuration.c,v 1.1 2013/03/16 19:41:36 jym Exp $

Workaround missing facilities (SunOS).

--- configuration.c.orig	2013-02-12 08:36:11.000000000 +0000
+++ configuration.c
@@ -637,13 +637,19 @@ void config_param_validate (char *k, cha
   else if (strcmp(k, CFG_SYSLOG_FACILITY) == 0) {
     r = 1;
     if (!strcmp(v, "auth") || !strcmp(v, "authpriv"))
+#ifdef LOG_AUTHPRIV
       cfg->SYSLOG_FACILITY = LOG_AUTHPRIV;
+#else
+      cfg->SYSLOG_FACILITY = LOG_AUTH;
+#endif
     else if (!strcmp(v, "cron"))
       cfg->SYSLOG_FACILITY = LOG_CRON;
     else if (!strcmp(v, "daemon"))
       cfg->SYSLOG_FACILITY = LOG_DAEMON;
+#ifdef LOG_FTP
     else if (!strcmp(v, "ftp"))
       cfg->SYSLOG_FACILITY = LOG_FTP;
+#endif
     else if (!strcmp(v, "local0"))
       cfg->SYSLOG_FACILITY = LOG_LOCAL0;
     else if (!strcmp(v, "local1"))
@@ -813,14 +819,21 @@ char * config_disp_hostport (char *host,
 const char * config_disp_log_facility (int facility) {
   switch (facility)
   {
+#ifdef LOG_AUTHPRIV
     case LOG_AUTHPRIV:
       return "authpriv";
+#else
+    case LOG_AUTH:
+      return "auth";
+#endif
     case LOG_CRON:
       return "cron";
     case LOG_DAEMON:
       return "daemon";
+#ifdef LOG_FTP
     case LOG_FTP:
       return "ftp";
+#endif
     case LOG_LOCAL0:
       return "local0";
     case LOG_LOCAL1:
