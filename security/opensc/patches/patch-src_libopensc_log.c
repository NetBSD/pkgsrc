$NetBSD: patch-src_libopensc_log.c,v 1.2 2015/09/07 19:59:42 gdt Exp $

--- src/libopensc/log.c.orig	2015-05-16 20:30:24.000000000 +0000
+++ src/libopensc/log.c
@@ -91,7 +91,13 @@ static void sc_do_log_va(sc_context_t *c
 	gettimeofday (&tv, NULL);
 	tm = localtime (&tv.tv_sec);
 	strftime (time_string, sizeof(time_string), "%H:%M:%S", tm);
-	r = snprintf(p, left, "0x%lx %s.%03ld ", (unsigned long)pthread_self(), time_string, tv.tv_usec / 1000);
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
