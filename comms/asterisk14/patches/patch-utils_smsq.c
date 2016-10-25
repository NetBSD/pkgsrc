$NetBSD: patch-utils_smsq.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- utils/smsq.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ utils/smsq.c
@@ -687,7 +687,7 @@ main (int argc, const char *argv[])
       snprintf (temp, sizeof(temp), "sms/.smsq-%d", (int)getpid ());
       mkdir ("sms", 0777);      /* ensure directory exists */
       mkdir (dir, 0777);        /* ensure directory exists */
-      snprintf (queuename, sizeof(queuename), "%s/%s.%ld-%d", dir, *queue ? queue : "0", (long)time (0), (int)getpid ());
+      snprintf (queuename, sizeof(queuename), "%s/%s.%jd-%d", dir, *queue ? queue : "0", (intmax_t)time (0), (int)getpid ());
       f = fopen (temp, "w");
       if (!f)
       {
