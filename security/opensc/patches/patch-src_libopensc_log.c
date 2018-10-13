$NetBSD: patch-src_libopensc_log.c,v 1.4 2018/10/13 10:54:05 mlelstv Exp $

--- src/libopensc/log.c.orig	2018-09-13 11:47:21.000000000 +0000
+++ src/libopensc/log.c
@@ -93,7 +93,13 @@ static void sc_do_log_va(sc_context_t *c
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
+		     time_string, (long) tv.tv_usec / 1000);
 #endif
 	p += r;
 	left -= r;
