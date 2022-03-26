$NetBSD: patch-posix_JackPosixThread.h,v 1.1 2022/03/26 22:36:20 tnn Exp $

Cast from from std::nullptr_t to pthread_t is not safe, because
size can be different. On SunOS LP64, pthread_t is unsigned int.

--- posix/JackPosixThread.h.orig	2021-07-15 06:18:26.000000000 +0000
+++ posix/JackPosixThread.h
@@ -46,10 +46,10 @@ class SERVER_EXPORT JackPosixThread : pu
     public:
 
         JackPosixThread(JackRunnableInterface* runnable, bool real_time, int priority, int cancellation)
-                : JackThreadInterface(runnable, priority, real_time, cancellation), fThread((jack_native_thread_t)NULL)
+                : JackThreadInterface(runnable, priority, real_time, cancellation), fThread((jack_native_thread_t)0)
         {}
         JackPosixThread(JackRunnableInterface* runnable, int cancellation = PTHREAD_CANCEL_ASYNCHRONOUS)
-                : JackThreadInterface(runnable, 0, false, cancellation), fThread((jack_native_thread_t)NULL)
+                : JackThreadInterface(runnable, 0, false, cancellation), fThread((jack_native_thread_t)0)
         {}
 
         int Start();
