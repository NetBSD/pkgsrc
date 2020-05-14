$NetBSD: patch-lib_threads_posix_semaphore.cpp,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/threads/posix/semaphore.cpp.orig	2020-05-13 19:40:46.833581962 +0000
+++ lib/threads/posix/semaphore.cpp
@@ -29,7 +29,7 @@
 #include <sys/time.h>
 #include <stdlib.h>
 #include <errno.h>
-#include "semaphore.h"
+#include "semaphore_.h"
 
 
 Semaphore::Semaphore(const char *name)
