$NetBSD: patch-ii.c,v 1.2 2025/10/12 14:41:44 vins Exp $

* Make sure PATH_MAX is defined. 
* Prevent type clash on SunOS.

--- ii.c.orig	2025-10-12 14:33:14.984921552 +0000
+++ ii.c
@@ -27,6 +27,10 @@ char *argv0;
 
 #include "arg.h"
 
+#ifndef PATH_MAX
+#define PATH_MAX _POSIX_PATH_MAX
+#endif
+
 #ifdef NEED_STRLCPY
 size_t strlcpy(char *, const char *, size_t);
 #endif /* NEED_STRLCPY */
@@ -369,19 +373,19 @@ loginuser(int ircfd, const char *host, c
 static int
 udsopen(const char *uds)
 {
-	struct sockaddr_un sun;
+	struct sockaddr_un lsun;
 	size_t len;
 	int fd;
 
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
 		die("%s: socket: %s\n", argv0, strerror(errno));
 
-	sun.sun_family = AF_UNIX;
-	if (strlcpy(sun.sun_path, uds, sizeof(sun.sun_path)) >= sizeof(sun.sun_path))
+	lsun.sun_family = AF_UNIX;
+	if (strlcpy(lsun.sun_path, uds, sizeof(lsun.sun_path)) >= sizeof(lsun.sun_path))
 		die("%s: UNIX domain socket path truncation\n", argv0);
 
-	len = strlen(sun.sun_path) + 1 + sizeof(sun.sun_family);
-	if (connect(fd, (struct sockaddr *)&sun, len) == -1)
+	len = strlen(lsun.sun_path) + 1 + sizeof(lsun.sun_family);
+	if (connect(fd, (struct sockaddr *)&lsun, len) == -1)
 		die("%s: connect: %s\n", argv0, strerror(errno));
 
 	return fd;
