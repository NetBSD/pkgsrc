$NetBSD: patch-loudmouth_lm-debug.c,v 1.1 2014/05/19 09:34:34 jperkin Exp $

Apply patch from

  https://github.com/mcabber/loudmouth/commit/65fda2c884f2cd70096def29fde5c6b9c1e70ecb

to avoid logging spam in the non-debug case.

--- loudmouth/lm-debug.c.orig	2008-10-29 13:45:10.000000000 +0000
+++ loudmouth/lm-debug.c
@@ -88,9 +88,17 @@ lm_debug_init (void)
 
 #else  /* LM_NO_DEBUG */
 
+static void
+do_nothing_log_handler (const gchar *log_domain, GLogLevelFlags log_level,
+			const gchar *message, gpointer user_data)
+{
+}
+
 void 
 lm_debug_init (void)
 {
+	g_log_set_handler (LM_LOG_DOMAIN, LM_LOG_LEVEL_ALL,
+			   do_nothing_log_handler, NULL);
 }
 
 #endif /* LM_NO_DEBUG */
