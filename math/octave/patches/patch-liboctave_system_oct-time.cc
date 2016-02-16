$NetBSD: patch-liboctave_system_oct-time.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- liboctave/system/oct-time.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ liboctave/system/oct-time.cc
@@ -85,7 +85,7 @@ octave_time::stamp (void)
 {
   struct timeval tp;
 
-  gnulib::gettimeofday (&tp, 0);
+  gettimeofday (&tp, 0);
 
   ot_unix_time = tp.tv_sec;
   ot_usec = tp.tv_usec;
