$NetBSD: patch-plugins_tracers_gstrusage.c,v 1.1 2016/04/15 14:20:00 wiz Exp $

Check for the symbol that is used.

--- plugins/tracers/gstrusage.c.orig	2016-02-15 14:49:05.000000000 +0000
+++ plugins/tracers/gstrusage.c
@@ -159,7 +159,7 @@ do_stats (GstTracer * obj, guint64 ts)
   GstClockTime tthread = G_GUINT64_CONSTANT (0);
   GstClockTime dts, dtproc;
 
-#ifdef HAVE_CLOCK_GETTIME
+#ifdef CLOCK_PROCESS_CPUTIME_ID
   {
     struct timespec now;
 
