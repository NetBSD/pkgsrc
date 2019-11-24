$NetBSD: patch-lib_availability.h,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8081/
Fix assorted crashes with xymongen report generation after string changes

--- lib/availability.h.orig	2011-07-31 21:01:52.000000000 +0000
+++ lib/availability.h
@@ -42,6 +42,7 @@ typedef struct replog_t {
 
 extern replog_t *reploghead;
 
+#define MAXDURSIZE 30
 extern char *durationstr(time_t duration);
 extern int parse_historyfile(FILE *fd, reportinfo_t *repinfo, char *hostname, char *servicename, 
 				time_t fromtime, time_t totime, int for_history,
