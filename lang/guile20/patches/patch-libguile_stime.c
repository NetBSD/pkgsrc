$NetBSD: patch-libguile_stime.c,v 1.1.2.2 2016/12/11 15:56:13 spz Exp $

Fix building on Darwin.

--- libguile/stime.c.orig	2016-10-19 07:55:02.000000000 +0000
+++ libguile/stime.c
@@ -828,7 +828,7 @@ scm_init_stime()
   if (clock_gettime (CLOCK_REALTIME, &posix_real_time_base) == 0)
     get_internal_real_time = get_internal_real_time_posix_timer;
 
-#ifdef HAVE_POSIX_CPUTIME
+#if defined(HAVE_POSIX_CPUTIME) && defined(HAVE_CLOCK_GETCPUCLOCKID)
   {
     clockid_t dummy;
     
