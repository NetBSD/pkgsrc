$NetBSD: patch-src_syslogd.c,v 1.1 2023/12/31 19:06:15 adam Exp $

Fix conflicting types error.

--- src/syslogd.c.orig	2023-12-31 19:00:12.282997217 +0000
+++ src/syslogd.c
@@ -278,7 +278,7 @@ void logerror (const char *);
 void logmsg (int, const char *, const char *, int);
 void printline (const char *, const char *);
 void printsys (const char *);
-char *ttymsg (struct iovec *, int, char *, int);
+char *ttymsg (struct iovec *, int, const char *, int);
 void wallmsg (struct filed *, struct iovec *);
 char **crunch_list (char **oldlist, char *list);
 char *textpri (int pri);
