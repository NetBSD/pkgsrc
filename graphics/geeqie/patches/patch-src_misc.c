$NetBSD: patch-src_misc.c,v 1.1 2019/07/30 13:03:18 ryoon Exp $

* _NL_TIME_FIRST_WEEKDAY is not universal and return Sunday=1 instead.

--- src/misc.c.orig	2019-07-26 18:19:11.000000000 +0000
+++ src/misc.c
@@ -249,7 +249,11 @@ int runcmd(gchar *cmd)
  */
 gint date_get_first_day_of_week()
 {
+#if defined(_NL_TIME_FIRST_WEEKDAY)
 	return nl_langinfo(_NL_TIME_FIRST_WEEKDAY)[0];
+#else
+	return 1;
+#endif
 }
 
 /**
