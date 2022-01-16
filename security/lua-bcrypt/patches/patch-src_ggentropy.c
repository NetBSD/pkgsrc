$NetBSD: patch-src_ggentropy.c,v 1.1 2022/01/16 13:41:13 nia Exp $

Add portable path for SunOS.
https://github.com/mikejsavage/lua-bcrypt/pull/18

--- src/ggentropy.c.orig	2021-12-22 18:57:54.000000000 +0000
+++ src/ggentropy.c
@@ -27,9 +27,6 @@
 
 #elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 #  define PLATFORM_HAS_ARC4RANDOM 1
-
-#else
-#  error new platform
 #endif
 
 #include <stdbool.h>
@@ -71,5 +68,18 @@ bool ggentropy( void * buf, size_t n ) {
 }
 
 #else
-#error new platform
+
+#include <fcntl.h>
+#include <unistd.h>
+
+bool ggentropy( void * buf, size_t n ) {
+	int fd = open("/dev/urandom", O_RDONLY);
+
+	if (fd != -1) {
+		int ret = read(fd, buf, n);
+		close(fd);
+		return ret == n;
+	}
+	return false;
+}
 #endif
