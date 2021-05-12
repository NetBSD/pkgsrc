$NetBSD: patch-alsactl_alsactl.c,v 1.1 2021/05/12 14:13:22 ryoon Exp $

--- alsactl/alsactl.c.orig	2020-10-15 11:32:33.000000000 +0000
+++ alsactl/alsactl.c
@@ -155,6 +155,9 @@ static void help(void)
 }
 
 #define NO_NICE (-100000)
+#if !defined(SCHED_IDLE)
+#define SCHED_IDLE SCHED_OTHER
+#endif
 
 static void do_nice(int use_nice, int sched_idle)
 {
