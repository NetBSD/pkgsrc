$NetBSD: patch-flowop.c,v 1.1.1.1 2012/07/02 17:43:16 asau Exp $

--- flowop.c.orig	2011-09-06 17:17:45.000000000 +0000
+++ flowop.c
@@ -164,7 +164,7 @@ flowop_beginop(threadflow_t *threadflow,
 			    threadflow->tf_susage.pr_stime);
 		}
 	}
-#elif defined(HAVE_PROC_PID_STAT)
+#elif HAVE_PROC_PID_STAT && HAVE_GETTID
 	int tid;
 	char fname[128], dummy_str[64];
 	unsigned long utime, stime;
@@ -263,7 +263,7 @@ flowop_endop(threadflow_t *threadflow, f
 		    TIMESPEC_TO_HRTIME(threadflow->tf_susage.pr_slptime,
 		    threadflow->tf_eusage.pr_slptime);
 	}
-#elif defined(HAVE_PROC_PID_STAT)
+#elif HAVE_PROC_PID_STAT && HAVE_GETTID
 	int tid;
 	char fname[128], dummy_str[64];
 	unsigned long utime, stime;
