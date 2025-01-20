$NetBSD: patch-subread.h,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Use standard compiler macros

--- subread.h.orig	2024-07-25 00:30:10.000000000 +0000
+++ subread.h
@@ -114,7 +114,7 @@
 #define USE_POSIX_MUTEX_LOCK
 #endif
 
-#if defined(MACOS) || defined(FREEBSD) || defined(USE_POSIX_MUTEX_LOCK)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(USE_POSIX_MUTEX_LOCK)
 typedef pthread_mutex_t subread_lock_t;
 #define pthread_spinlock_t pthread_mutex_t
 #define pthread_spin_lock pthread_mutex_lock
