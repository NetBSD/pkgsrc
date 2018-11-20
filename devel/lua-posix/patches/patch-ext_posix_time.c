$NetBSD: patch-ext_posix_time.c,v 1.1 2018/11/20 17:45:38 maya Exp $

Only use CLOCK_{PROCESS,THREAD}_CPUTIME_ID if defined

--- ext/posix/time.c.orig	2018-11-20 17:41:28.954287969 +0000
+++ ext/posix/time.c
@@ -350,10 +350,14 @@ luaopen_posix_time(lua_State *L)
 
 #if defined _POSIX_TIMERS && _POSIX_TIMERS != -1
 	LPOSIX_CONST( CLOCK_MONOTONIC		);
+#if defined CLOCK_PROCESS_CPUTIME_ID
 	LPOSIX_CONST( CLOCK_PROCESS_CPUTIME_ID	);
+#endif
 	LPOSIX_CONST( CLOCK_REALTIME		);
+#if defined CLOCK_THREAD_CPUTIME_ID
 	LPOSIX_CONST( CLOCK_THREAD_CPUTIME_ID	);
 #endif
+#endif
 
 	return 1;
 }
