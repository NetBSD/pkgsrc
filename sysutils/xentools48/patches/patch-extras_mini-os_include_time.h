$NetBSD: patch-extras_mini-os_include_time.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- extras/mini-os/include/time.h.orig	2016-09-28 13:09:38.000000000 +0200
+++ extras/mini-os/include/time.h	2017-03-28 20:00:33.000000000 +0200
@@ -48,7 +48,7 @@
 
 #include <sys/time.h>
 
-#ifdef HAVE_LIBC
+#if defined(HAVE_LIBC) && defined(NEED_TIME_H)
 #include_next <time.h>
 #endif
 
