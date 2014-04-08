$NetBSD: patch-libtest_alarm.cc,v 1.1 2014/04/08 13:23:31 fhajny Exp $

Fix narrowing conversion on NetBSD.

--- libtest/alarm.cc.orig	2014-02-09 11:52:42.000000000 +0000
+++ libtest/alarm.cc
@@ -76,7 +76,7 @@ void set_alarm(long tv_sec, long tv_usec
     }
   }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
   struct timeval it_value= { time_t(tv_sec), suseconds_t(tv_usec) };
 #else
   struct timeval it_value= { tv_sec, tv_usec };
