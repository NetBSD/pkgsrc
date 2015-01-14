$NetBSD: patch-src_timezone_localtime.c,v 1.1 2015/01/14 21:01:18 adam Exp $

--- src/timezone/localtime.c.orig	2009-06-11 16:49:15.000000000 +0200
+++ src/timezone/localtime.c
@@ -81,20 +81,20 @@ static pg_time_t detzcode64(const char *
 static int	differ_by_repeat(pg_time_t t1, pg_time_t t0);
 static const char *getzname(const char *strp);
 static const char *getqzname(const char *strp, int delim);
-static const char *getnum(const char *strp, int *nump, int min, int max);
+static const char *getnum(const char *strp, int *nump, const int min, const int max);
 static const char *getsecs(const char *strp, long *secsp);
 static const char *getoffset(const char *strp, long *offsetp);
 static const char *getrule(const char *strp, struct rule * rulep);
 static void gmtload(struct state * sp);
-static struct pg_tm *gmtsub(const pg_time_t *timep, long offset,
+static struct pg_tm *gmtsub(const pg_time_t *timep, const long offset,
 	   struct pg_tm * tmp);
-static struct pg_tm *localsub(const pg_time_t *timep, long offset,
+static struct pg_tm *localsub(const pg_time_t *timep, const long offset,
 		 struct pg_tm * tmp, const pg_tz *tz);
 static int	increment_overflow(int *number, int delta);
-static pg_time_t transtime(pg_time_t janfirst, int year,
-		  const struct rule * rulep, long offset);
+static pg_time_t transtime(pg_time_t janfirst, const int year,
+		  const struct rule * rulep, const long offset);
 static int	typesequiv(const struct state * sp, int a, int b);
-static struct pg_tm *timesub(const pg_time_t *timep, long offset,
+static struct pg_tm *timesub(const pg_time_t *timep, const long offset,
 		const struct state * sp, struct pg_tm * tmp);
 
 /* GMT timezone */
