$NetBSD: patch-dist_Time-HiRes_HiRes.xs,v 1.1 2016/08/31 13:24:06 adam Exp $

Fix for OS X 10.12, where clock_gettime() is defined.

--- dist/Time-HiRes/HiRes.xs.orig	2016-08-31 15:04:18.000000000 +0200
+++ dist/Time-HiRes/HiRes.xs	2016-08-31 15:05:29.000000000 +0200
@@ -747,6 +747,10 @@
 #endif /* !TIME_HIRES_STAT */
 }
 
+#if defined(USE_ITHREADS) && defined(PERL_DARWIN)
+STATIC perl_mutex darwin_time_mutex;
+#endif
+
 /* Until Apple implements clock_gettime() (ditto clock_getres())
  * we will emulate it using Mach interfaces. */
 #if defined(PERL_DARWIN) && !defined(CLOCK_REALTIME)
@@ -758,9 +762,6 @@
 
 #  define TIMER_ABSTIME   0x01
 
-#ifdef USE_ITHREADS
-STATIC perl_mutex darwin_time_mutex;
-#endif
 
 static uint64_t absolute_time_init;
 static mach_timebase_info_data_t timebase_info;
