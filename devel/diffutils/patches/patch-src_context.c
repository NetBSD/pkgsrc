$NetBSD: patch-src_context.c,v 1.2 2019/07/07 18:02:44 schwarz Exp $

date: 2009-03-10 23:06:06 +0900;  author: apb;  state: Exp;
Fix a build failure on platforms where time_t is larger than long, by
using long long instead.  (Not using time_t, because there's no easy and
portable printf format for time_t.)

--- src/context.c.orig	2018-12-31 07:22:10.000000000 +0100
+++ src/context.c	2019-07-07 00:38:26.000000000 +0200
@@ -58,8 +58,8 @@
 	  if (LONG_MIN <= TYPE_MINIMUM (time_t)
 	      && TYPE_MAXIMUM (time_t) <= LONG_MAX)
 	    {
-	      long int sec = inf->stat.st_mtime;
-	      sprintf (buf, "%ld.%.9d", sec, nsec);
+	      long long int sec = inf->stat.st_mtime; /* should really be time_t */
+	      sprintf (buf, "%lld.%.9d", sec, nsec);
 	    }
 	  else if (TYPE_MAXIMUM (time_t) <= INTMAX_MAX)
 	    {
