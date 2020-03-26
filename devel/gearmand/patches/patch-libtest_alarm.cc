$NetBSD: patch-libtest_alarm.cc,v 1.1 2020/03/26 21:49:49 joerg Exp $

--- libtest/alarm.cc.orig	2020-03-26 14:51:14.108759483 +0000
+++ libtest/alarm.cc
@@ -90,12 +90,7 @@ void set_alarm(long tv_sec, long tv_usec
       }
     }
 
-#ifdef __APPLE__
     struct timeval it_value= { time_t(tv_sec), suseconds_t(tv_usec) };
-#else
-    struct timeval it_value= { tv_sec, tv_usec };
-#endif
-
     struct itimerval timer= { default_it_interval, it_value };
 
     if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1)
