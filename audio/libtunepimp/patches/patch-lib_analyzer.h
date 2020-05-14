$NetBSD: patch-lib_analyzer.h,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/analyzer.h.orig	2020-05-13 19:40:40.918058734 +0000
+++ lib/analyzer.h
@@ -28,7 +28,7 @@
 #define __ANALYZER_H__
 
 #include "thread.h"
-#include "semaphore.h"
+#include "semaphore_.h"
 #include "track.h"
 #include "plugin.h"
 
