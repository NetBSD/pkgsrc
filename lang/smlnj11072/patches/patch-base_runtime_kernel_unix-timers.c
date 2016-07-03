$NetBSD: patch-base_runtime_kernel_unix-timers.c,v 1.1 2016/07/03 18:52:32 dholland Exp $

Don't blithely assume that some internal type has the same layout as a
system type. It doesn't. Same issue as PR 40954, but a new case that I
either didn't find at the time or has appeared since.

--- base/runtime/kernel/unix-timers.c~	2000-06-01 18:34:03.000000000 +0000
+++ base/runtime/kernel/unix-timers.c
@@ -18,7 +18,7 @@ typedef struct rusage time_struct_t;
 #define GET_TIME(t)		getrusage(RUSAGE_SELF, &(t))
 #define SYS_TIME(t)		((t).ru_stime)
 #define USR_TIME(t)		((t).ru_utime)
-#define SET_TIME(tp, t)		{ *((struct timeval *)(tp)) = (t); }
+#define SET_TIME(tp, t)		{ (tp)->seconds = (t).tv_sec; (tp)->uSeconds = (t).tv_usec; }
 
 #else /* !HAS_GETRUSAGE */
 
