$NetBSD: patch-lib_threads_posix_thread.h,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/threads/posix/thread.h.orig	2020-05-13 19:40:49.579909635 +0000
+++ lib/threads/posix/thread.h
@@ -29,7 +29,7 @@
 
 #include <pthread.h>
 #include <signal.h>
-#include "semaphore.h"
+#include "semaphore_.h"
 
 #include "defs.h"
 
