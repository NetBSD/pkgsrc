$NetBSD: patch-src_test__override.c,v 1.3 2023/01/17 10:18:33 wiz Exp $

Match NetBSD prototype for gettimeofday().
https://github.com/tstack/lnav/pull/1106

--- src/test_override.c.orig	2015-04-04 10:42:12.000000000 +0000
+++ src/test_override.c
@@ -47,7 +47,7 @@ time_t time(time_t *loc)
     return retval;
 }
 
-int gettimeofday(struct timeval *tv, struct timezone *tz)
+int gettimeofday(struct timeval *tv, void *tz)
 {
     tv->tv_sec = 1370546000;
     tv->tv_usec = 123456;
