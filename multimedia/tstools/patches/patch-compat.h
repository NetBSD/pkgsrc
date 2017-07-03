$NetBSD: patch-compat.h,v 1.1 2017/07/03 11:52:37 wiedi Exp $

prevent conflicting offset_t on SunOS

--- compat.h.orig	2008-11-06 23:15:49.000000000 +0000
+++ compat.h
@@ -113,7 +113,9 @@ typedef uint8_t  byte;
 //     do both, here, for safety.
 #include <sys/types.h>
 #include <unistd.h>
+#if !defined(__sun)
 typedef off_t offset_t;
+#endif
 
 #if defined(__linux__) && !defined(__USE_FILE_OFFSET64)
 // If Linux does not have 64 bit support built in, then our offsets will
