$NetBSD: patch-src_libopensc_log.c,v 1.3 2016/08/04 13:08:25 mef Exp $

--- src/libopensc/log.c.orig	2016-05-31 16:36:09.000000000 +0900
+++ src/libopensc/log.c	2016-08-04 21:52:53.000000000 +0900
@@ -91,7 +91,13 @@ static void sc_do_log_va(sc_context_t *c
 	gettimeofday (&tv, NULL);
 	tm = localtime (&tv.tv_sec);
 	strftime (time_string, sizeof(time_string), "%H:%M:%S", tm);
-	r = snprintf(p, left, "0x%lx %s.%03ld ", (unsigned long)pthread_self(), time_string, (long)tv.tv_usec / 1000);
+	r = snprintf(p, left, "0x%lx %s.%03ld ",
+#ifdef HAVE_PTHREAD
+		     (unsigned long)pthread_self(),
+#else
+		     (unsigned long) 0,
+#endif
+		     time_string, tv.tv_usec / 1000);
 #endif
 	p += r;
 	left -= r;
