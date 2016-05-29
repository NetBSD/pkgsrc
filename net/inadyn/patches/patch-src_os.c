$NetBSD: patch-src_os.c,v 1.2 2016/05/29 22:32:12 abs Exp $

Avoid possible usleep overflow

--- src/os.c.orig	2015-09-09 19:27:51.000000000 +0000
+++ src/os.c
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
