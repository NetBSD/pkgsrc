$NetBSD: patch-src_os.c,v 1.1 2015/04/04 07:59:34 snj Exp $

Avoid bogus usleep usage.

--- src/os.c.orig	2015-04-03 21:12:49.000000000 -0700
+++ src/os.c	2015-04-03 21:19:49.000000000 -0700
@@ -180,7 +180,11 @@ static void *param = NULL;
 
 void os_sleep_ms(int ms)
 {
-	usleep(ms * 1000);
+	/* usleep is not guaranteed to work for arguments >= 1,000,000 */
+	if (ms >= 1000)
+		sleep(ms / 1000);
+	else
+		usleep(ms * 1000);
 }
 
 int os_get_socket_error(void)
