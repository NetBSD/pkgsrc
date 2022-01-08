$NetBSD: patch-arjtypes.c,v 1.1 2022/01/08 14:43:09 tnn Exp $

Description: Use proper time_t type instead of unsigned long for variables
 that are being passed to localhost() and gmtime(). This fixes several
 segfaults on x32.
Author: Guillem Jover <guillem@debian.org>
Origin: vendor
Forwarded: no
Last-Update: 2019-08-11

--- arjtypes.c.orig	2005-06-23 10:00:54.000000000 +0000
+++ arjtypes.c
@@ -135,11 +135,11 @@ static int isleapyear(int year)
 
 /* Converts a UNIX timestamp to the DOS style */
 
-static unsigned long ts_unix2dos(const long ts)
+static unsigned long ts_unix2dos(time_t ts)
 {
  struct tm *stm;
 
- stm=arj_localtime((time_t*)&ts);
+ stm=arj_localtime(&ts);
  return(get_tstamp(stm->tm_year+1900, stm->tm_mon+1, stm->tm_mday,
         stm->tm_hour, stm->tm_min, stm->tm_sec));
 }
@@ -148,14 +148,14 @@ static unsigned long ts_unix2dos(const l
 
 static unsigned long mk_unixtime(int y, int m, int d, int hh, int mm, int ss)
 {
- unsigned long u=0, ts;
+ unsigned long u=0;
  unsigned int i, v;
  /* Clash with NetBSD/x86-64 patch: leaving rc as unsigned long still permits
     to escape the year 2038 problem in favor of year 2106 problem, while a
     dedicated time_t structure can be expected as a 64-bit value on relevant
     platforms -- ASR fix 25/01/2004 */
- unsigned long rc;
- time_t tt;
+ time_t rc;
+ time_t tt, ts;
  long tzshift, shiftd1, shiftd2;
  struct tm *stm;
 
@@ -191,7 +191,7 @@ static unsigned long mk_unixtime(int y, 
    u+=isleapyear(y);
  }
  rc=86400*(unsigned long)(u+d-1)+(unsigned long)hh*3600+(unsigned long)mm*60+(unsigned long)ss;
- stm=arj_localtime((const long *)&rc);
+ stm=arj_localtime(&rc);
  debug_assert(stm!=NULL);               /* LIBCS.DLL returns NULL for unixtime beyond
                                            0x7FFFFFFF */
  tzshift=(long)stm->tm_hour*3600+(long)stm->tm_min*60;
@@ -203,7 +203,7 @@ static unsigned long mk_unixtime(int y, 
   debug_assert(stm!=NULL);
   stm->tm_year+=v;
  #else
-  stm=gmtime((const long *)&ts);  
+  stm=gmtime(&ts);
  #endif
  shiftd2=stm->tm_mday;
  /* Local time overruns GMT, add 24 hours for safety */
@@ -304,8 +304,9 @@ void make_timestamp(struct timestamp *de
 void timestamp_to_str(char *str, struct timestamp *ts)
 {
  struct tm *stm;
+ time_t ut = ts->unixtime;
 
- stm=arj_localtime((time_t *)&ts->unixtime);
+ stm=arj_localtime(&ut);
  /* Workaround for a MS C v 7.0 CRT bug */
  #if TARGET==DOS&&COMPILER==MSC&&_MSC_VER==700
   if(stm->tm_year<70)                   /* 31 -> 101 */
