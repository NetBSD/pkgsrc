$NetBSD: patch-src_flow-print.c,v 1.1 2013/10/13 21:52:44 sbd Exp $

--- src/flow-print.c.orig	2003-04-02 18:03:02.000000000 +0000
+++ src/flow-print.c
@@ -298,6 +298,7 @@ int format1(struct ftio *ftio, int optio
   u_long bpp;
   char fmt_buf1[64], fmt_buf2[64];
   char *rec;
+  time_t time_tmp;
 
   if (ftio_check_xfield(ftio, FT_XFIELD_DPKTS |
     FT_XFIELD_DOCTETS | FT_XFIELD_FIRST | FT_XFIELD_LAST | FT_XFIELD_INPUT |
@@ -351,14 +352,16 @@ int format1(struct ftio *ftio, int optio
       (u_long)*cur.dPkts, (u_long)*cur.dOctets);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.First);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     printf(" %-2.2d%-2.2d.%-2.2d:%-2.2d:%-2.2d.%-3.3lu  ",
       (int)tm->tm_mon+1, (int)tm->tm_mday, (int)tm->tm_hour,
       (int)tm->tm_min, (int)tm->tm_sec, (u_long)ftt.msecs);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.Last);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     active_secs = (*cur.Last - *cur.First) / 1000;
     active_msecs = (*cur.Last - *cur.First) % 1000;
@@ -398,6 +401,7 @@ int format2(struct ftio *ftio, int optio
   u_long active_secs, active_msecs;
   u_long bpp;
   char *rec;
+  time_t time_tmp;
 
   if (ftio_check_xfield(ftio, FT_XFIELD_DPKTS |
     FT_XFIELD_DOCTETS | FT_XFIELD_FIRST | FT_XFIELD_LAST | FT_XFIELD_INPUT |
@@ -465,14 +469,16 @@ int format2(struct ftio *ftio, int optio
       (u_long)*cur.dPkts, (u_long)*cur.dOctets);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.First);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     printf(" %-2.2d%-2.2d.%-2.2d:%-2.2d:%-2.2d.%-3.3lu  ",
       (int)tm->tm_mon+1, (int)tm->tm_mday, (int)tm->tm_hour, (int)tm->tm_min,
       (int)tm->tm_sec, (u_long)ftt.msecs);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.Last);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     active_secs = (*cur.Last - *cur.First) / 1000;
     active_msecs = (*cur.Last - *cur.First) % 1000;
@@ -675,6 +681,7 @@ int format5(struct ftio *ftio, int optio
   struct ftver ftv;
   char fmt_buf1[64], fmt_buf2[64];
   char *rec;
+  time_t time_tmp;
 
   if (ftio_check_xfield(ftio, FT_XFIELD_DPKTS |
     FT_XFIELD_DOCTETS | FT_XFIELD_FIRST | FT_XFIELD_LAST | FT_XFIELD_INPUT |
@@ -711,14 +718,16 @@ int format5(struct ftio *ftio, int optio
     cur.tcp_flags = ((u_int8*)(rec+fo.tcp_flags));
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.First);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     printf("%-2.2d%-2.2d.%-2.2d:%-2.2d:%-2.2d.%-3.3lu ",
       (int)tm->tm_mon+1, (int)tm->tm_mday, (int)tm->tm_hour,
       (int)tm->tm_min, (int)tm->tm_sec, (u_long)ftt.msecs);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.Last);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     printf("%-2.2d%-2.2d.%-2.2d:%-2.2d:%-2.2d.%-3.3lu ",
       (int)tm->tm_mon+1, (int)tm->tm_mday, (int)tm->tm_hour,
@@ -2173,6 +2182,7 @@ int format24(struct ftio *ftio, int opti
   u_long bpp;
   char fmt_buf1[64], fmt_buf2[64], fmt_buf3[64], fmt_buf4[64], fmt_buf5[64], fmt_buf6[64];
   char *rec;
+  time_t time_tmp;
 
   if (ftio_check_xfield(ftio, FT_XFIELD_DPKTS |
     FT_XFIELD_DOCTETS | FT_XFIELD_FIRST | FT_XFIELD_LAST | FT_XFIELD_INPUT |
@@ -2239,14 +2249,16 @@ int format24(struct ftio *ftio, int opti
       (u_long)*cur.dPkts, (u_long)*cur.dOctets);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.First);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     printf(" %-4.4d-%-2.2d-%-2.2d %-2.2d:%-2.2d:%-2.2d.%-3.3lu  ",
       (int)tm->tm_year+1900, (int)tm->tm_mon+1, (int)tm->tm_mday, (int)tm->tm_hour,
       (int)tm->tm_min, (int)tm->tm_sec, (u_long)ftt.msecs);
 
     ftt = ftltime(*cur.sysUpTime, *cur.unix_secs, *cur.unix_nsecs, *cur.Last);
-    tm = localtime((time_t*)&ftt.secs);
+    time_tmp = ftt.secs;
+    tm = localtime(&time_tmp);
 
     active_secs = (*cur.Last - *cur.First) / 1000;
     active_msecs = (*cur.Last - *cur.First) % 1000;
