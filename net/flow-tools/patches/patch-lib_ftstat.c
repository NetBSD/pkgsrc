$NetBSD: patch-lib_ftstat.c,v 1.1 2013/10/13 21:52:44 sbd Exp $

--- lib/ftstat.c.orig	2005-05-10 15:48:12.000000000 +0000
+++ lib/ftstat.c
@@ -12363,7 +12363,7 @@ static int dump_ascii_header(FILE *fp, s
 {
   int comma, sort_field;
   char *buf, fmt_buf[32];
-  time_t now;
+  time_t now, time_tmp;
 
   /* shortcut */
   if (!(rpt->out->options & FT_STAT_OPT_HEADER))
@@ -12619,11 +12619,13 @@ static int dump_ascii_header(FILE *fp, s
     fprintf(fp, "# records_shown:      %s\n", fmt_buf);
   }
 
+  time_tmp = rpt->time_start;
   fprintf(fp, "# first-flow:           %lu %s",
-    (unsigned long)rpt->time_start, ctime((time_t*)&rpt->time_start));
+    (unsigned long)rpt->time_start, ctime(&time_tmp));
 
+  time_tmp = rpt->time_end;
   fprintf(fp, "# last-flow:            %lu %s",
-    (unsigned long)rpt->time_end, ctime((time_t*)&rpt->time_end));
+    (unsigned long)rpt->time_end, ctime(&time_tmp));
 
   now = time((time_t*)0L);
 
