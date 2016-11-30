$NetBSD: patch-src_core_src_logger.cpp,v 1.2 2016/11/30 12:43:36 wiz Exp $

usleep(1000000) is illegal.
https://github.com/hydrogen-music/hydrogen/pull/444

--- src/core/src/logger.cpp.orig	2014-09-09 11:39:33.000000000 -0700
+++ src/core/src/logger.cpp	2016-10-24 14:40:32.000000000 -0700
@@ -31,7 +31,7 @@
 #define LOGGER_SLEEP Sleep( 100 )
 #else
 #include <unistd.h>
-#define LOGGER_SLEEP usleep( 1000000 )
+#define LOGGER_SLEEP do { usleep( 500000 ); usleep( 500000 ); } while (0)
 #endif
 
 namespace H2Core {
