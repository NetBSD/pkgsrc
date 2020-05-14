$NetBSD: patch-lib_write.h,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/write.h.orig	2020-05-13 19:40:54.215206075 +0000
+++ lib/write.h
@@ -28,7 +28,7 @@
 #define WRITE_H
 
 #include "thread.h"
-#include "semaphore.h"
+#include "semaphore_.h"
 #include "track.h"
 #include "context.h"
 #include "plugins.h"
