$NetBSD: patch-src_timezone_strftime.c,v 1.1 2016/02/25 21:37:35 tnn Exp $

--- src/timezone/strftime.c.orig	2009-06-11 16:49:15.000000000 +0200
+++ src/timezone/strftime.c
@@ -89,7 +89,7 @@ static const struct lc_time_T C_time_loc
 };
 
 static char *_add(const char *, char *, const char *);
-static char *_conv(int, const char *, char *, const char *);
+static char *_conv(const int, const char *, char *, const char *);
 static char *_fmt(const char *, const struct pg_tm *, char *,
 	 const char *, int *);
 static char *_yconv(const int, const int, const int, const int,
