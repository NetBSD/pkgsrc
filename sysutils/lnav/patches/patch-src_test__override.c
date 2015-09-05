$NetBSD: patch-src_test__override.c,v 1.1 2015/09/05 22:12:04 wiz Exp $

Match NetBSD version of gettimeofday().

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
