$NetBSD: patch-corelib_thread.cpp,v 1.1 2019/01/13 18:21:24 adam Exp $

Fix building on Darwin.

--- corelib/thread.cpp.orig	2019-01-13 16:03:59.000000000 +0000
+++ corelib/thread.cpp
@@ -27,6 +27,11 @@
 #include <stdarg.h>
 #include <limits.h>
 
+#if defined(__APPLE__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #if _POSIX_PRIORITY_SCHEDULING > 0
 #include <sched.h>
 static int realtime_policy = SCHED_FIFO;
@@ -1287,7 +1292,11 @@ void Thread::init(void)
 
 size_t Thread::cache(void)
 {
+#if defined(__APPLE__)
+    static size_t line_size = 0;
+#else
     static volatile size_t line_size = 0;
+#endif
 
     if(line_size)
         return line_size;
@@ -1311,7 +1320,6 @@ size_t Thread::cache(void)
     free(buffer);
     return line_size;
 #elif defined(__APPLE__)
-    size_t line_size = 0;
     size_t sizeof_line_size = sizeof(line_size);
     sysctlbyname("hw.cachelinesize", &line_size, &sizeof_line_size, 0, 0);
     return line_size;
