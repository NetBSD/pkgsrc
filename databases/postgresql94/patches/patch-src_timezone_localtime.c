$NetBSD: patch-src_timezone_localtime.c,v 1.2 2016/08/14 16:56:29 is Exp $

--- src/timezone/localtime.c.orig	2016-08-08 20:29:39.000000000 +0000
+++ src/timezone/localtime.c
@@ -84,7 +84,7 @@ struct rule
  * Prototypes for static functions.
  */
 
-static struct pg_tm *gmtsub(pg_time_t const *, int32, struct pg_tm *);
+static struct pg_tm *gmtsub(pg_time_t const *, const int32, struct pg_tm *);
 static bool increment_overflow(int *, int);
 static bool increment_overflow_time(pg_time_t *, int32);
 static struct pg_tm *timesub(pg_time_t const *, int32, struct state const *,
