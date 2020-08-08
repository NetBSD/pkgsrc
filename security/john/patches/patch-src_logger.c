$NetBSD: patch-src_logger.c,v 1.1 2020/08/08 02:09:01 leot Exp $

Properly define _XOPEN_SOURCE.

--- src/logger.c.orig	2015-05-31 06:38:14.000000000 +0000
+++ src/logger.c
@@ -8,7 +8,7 @@
  * There's ABSOLUTELY NO WARRANTY, express or implied.
  */
 
-#define _XOPEN_SOURCE /* for fileno(3) and fsync(2) */
+#define _XOPEN_SOURCE 500 /* for fileno(3) and fsync(2) */
 
 #define NEED_OS_FLOCK
 #include "os.h"
