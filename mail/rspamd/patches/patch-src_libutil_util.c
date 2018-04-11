$NetBSD: patch-src_libutil_util.c,v 1.3 2018/04/11 15:32:39 fhajny Exp $

Fix SunOS workaround.

--- src/libutil/util.c.orig	2018-04-10 16:12:46.000000000 +0000
+++ src/libutil/util.c
@@ -2766,8 +2766,8 @@ rspamd_gmtime (gint64 ts, struct tm *des
 	dest->tm_sec = remsecs % 60;
 #if !defined(__sun)
 	dest->tm_gmtoff = 0;
-#endif
 	dest->tm_zone = "GMT";
+#endif
 }
 
 void
