$NetBSD: patch-src_util_screensaver.h,v 1.1 2019/07/08 16:46:32 nia Exp $

Reuse the Linux code for other platforms.

--- src/util/screensaver.h.orig	2019-07-08 15:16:40.065320358 +0000
+++ src/util/screensaver.h
@@ -28,7 +28,7 @@ private:
     /* sleep management */
     static IOPMAssertionID s_systemSleepAssertionID;
     static IOPMAssertionID s_userActivityAssertionID;
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     static uint32_t s_cookie;
     static int s_saverindex;
 #endif // Q_OS_MAC
