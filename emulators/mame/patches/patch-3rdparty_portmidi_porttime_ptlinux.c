$NetBSD: patch-3rdparty_portmidi_porttime_ptlinux.c,v 1.1 2015/07/14 20:14:49 wiz Exp $

ftime() is obsolete.

--- 3rdparty/portmidi/porttime/ptlinux.c.orig	2015-06-24 09:53:30.000000000 +0000
+++ 3rdparty/portmidi/porttime/ptlinux.c
@@ -38,7 +38,7 @@ CHANGE LOG
 #define FALSE 0
 
 static int time_started_flag = FALSE;
-static struct timeb time_offset = {0, 0, 0, 0};
+static struct timeval time_offset = {0, 0};
 static pthread_t pt_thread_pid;
 static int pt_thread_created = FALSE;
 
@@ -79,7 +79,7 @@ static void *Pt_CallbackProc(void *p)
 PtError Pt_Start(int resolution, PtCallback *callback, void *userData)
 {
     if (time_started_flag) return ptNoError;
-    ftime(&time_offset); /* need this set before process runs */
+    gettimeofday(&time_offset, NULL); /* need this set before process runs */
     if (callback) {
         int res;
         pt_callback_parameters *parms = (pt_callback_parameters *) 
@@ -121,10 +121,10 @@ int Pt_Started()
 PtTimestamp Pt_Time()
 {
     long seconds, milliseconds;
-    struct timeb now;
-    ftime(&now);
-    seconds = now.time - time_offset.time;
-    milliseconds = now.millitm - time_offset.millitm;
+    struct timeval now;
+    gettimeofday(&now, NULL);
+    seconds = now.tv_sec - time_offset.tv_sec;
+    milliseconds = now.tv_usec - time_offset.tv_usec;
     return seconds * 1000 + milliseconds;
 }
 
