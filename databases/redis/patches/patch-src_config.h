$NetBSD: patch-src_config.h,v 1.3 2023/10/06 07:27:44 triaxx Exp $

Fix building on Darwin from
https://github.com/redis/redis/issues/12585#issuecomment-1729243412

--- src/config.h.orig	2023-09-06 17:56:15.000000000 +0000
+++ src/config.h
@@ -31,6 +31,7 @@
 #define __CONFIG_H
 
 #ifdef __APPLE__
+#define _DARWIN_C_SOURCE
 #include <fcntl.h> // for fcntl(fd, F_FULLFSYNC)
 #include <AvailabilityMacros.h>
 #endif
