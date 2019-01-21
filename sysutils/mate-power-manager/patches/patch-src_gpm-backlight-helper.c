$NetBSD: patch-src_gpm-backlight-helper.c,v 1.1 2019/01/21 13:12:32 youri Exp $

Disable backlight helper for non linux.

--- src/gpm-backlight-helper.c.orig	2018-01-29 14:50:11.000000000 +0000
+++ src/gpm-backlight-helper.c
@@ -146,6 +146,9 @@ out:
 gint
 main (gint argc, gchar *argv[])
 {
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+	return GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED;
+#endif
 	GOptionContext *context;
 	gint uid;
 	gint euid;
