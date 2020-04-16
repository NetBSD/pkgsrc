$NetBSD: patch-src_libopensc_log.c,v 1.5 2020/04/16 12:37:51 manu Exp $

Build without pthread

--- src/libopensc/log.c.orig	2019-12-29 12:42:06.000000000 +0000
+++ src/libopensc/log.c	2020-04-15 13:00:39.853594605 +0000
@@ -112,9 +112,14 @@
 	sc_color_fprintf(SC_COLOR_FG_GREEN|SC_COLOR_BOLD,
 			ctx, ctx->debug_file,
 			"P:%lu; T:0x%lu",
 			(unsigned long)getpid(),
-			(unsigned long)pthread_self());
+#ifdef HAVE_PTHREAD
+			(unsigned long)pthread_self()
+#else
+			0UL
+#endif
+	);
 	gettimeofday (&tv, NULL);
 	tm = localtime (&tv.tv_sec);
 	strftime (time_string, sizeof(time_string), "%H:%M:%S", tm);
 	sc_color_fprintf(SC_COLOR_FG_GREEN,
