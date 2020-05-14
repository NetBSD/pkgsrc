$NetBSD: patch-lib_watchdog.h,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/watchdog.h.orig	2020-05-13 19:40:52.260133750 +0000
+++ lib/watchdog.h
@@ -28,7 +28,7 @@
 #define __WATCHDOG_H__
 
 #include "thread.h"
-#include "semaphore.h"
+#include "semaphore_.h"
 #include "mutex.h"
 
 class TunePimp;
