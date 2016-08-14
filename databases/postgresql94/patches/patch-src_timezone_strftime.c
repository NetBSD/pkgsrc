$NetBSD: patch-src_timezone_strftime.c,v 1.2 2016/08/14 16:56:29 is Exp $

--- src/timezone/strftime.c.orig	2016-08-08 20:29:39.000000000 +0000
+++ src/timezone/strftime.c
@@ -109,7 +109,7 @@ static const struct lc_time_T C_time_loc
 };
 
 static char *_add(const char *, char *, const char *);
-static char *_conv(int, const char *, char *, const char *);
+static char *_conv(const int, const char *, char *, const char *);
 static char *_fmt(const char *, const struct pg_tm *, char *,
 	 const char *, int *);
 static char *_yconv(int, int, bool, bool, char *, const char *);
