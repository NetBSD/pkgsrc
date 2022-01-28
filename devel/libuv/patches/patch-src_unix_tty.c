$NetBSD: patch-src_unix_tty.c,v 1.1 2022/01/28 21:13:10 schmonz Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/tty.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/tty.c
@@ -72,7 +72,7 @@ static int uv__tty_is_slave(const int fd
   int dummy;
 
   result = ioctl(fd, TIOCGPTN, &dummy) != 0;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1050
   char dummy[256];
 
   result = ioctl(fd, TIOCPTYGNAME, &dummy) != 0;
